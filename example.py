import scrapy
from scrapy_playwright.page import PageMethod

class ExampleSpider(scrapy.Spider):
    name = "example"
    def start_requests(self):
        yield scrapy.Request(
            url="https://quotes.toscrape.com/",
            callback=self.parse,
            page_methods=[
                PageMethod("wait_for_selector", "div.quote")
            ]

        )

    def parse(self, response):
        for post in response.css("div.quote"):
            yield {
                "author": post.css("small.author::text").get(),
                "quote": post.css("span.text::text").get(),
            }
        pass

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

//VERy GOOD APPLICATION of disjoint set union bas tumhe parent aur size vector declare karo dono hi zaruri hai aur find parent aur union find function banao as it is jaise isme banaye hai ab kya karo saare edges k liye union find karo ye general union find me hota hai components k liye 

//ye dono function use karne k baad jo hamare paas rehta hai ki ultimate parent of all the nodes 
//jaha jaha parent[i]=i matlab utne different components 
//so you ca get the idea of different components 
    int findParent(int i,vector<int>& parent) // ye find parent function hai jisme tum parent vector pass karo aur i pass karo aur ye tumhe ultimate parent dega
    {
        if(i==parent[i]) // agar i ka parent i hai toh i return karo
        {
            return i; 
        }
        return parent[i]=findParent(parent[i],parent); // nahi toh parent[i] ka parent dhundho
    }

    void unionFind(int u,int v,vector<int>& parent,vector<int>& size)
    {
        int pu=findParent(u,parent); // pu is parent of u
        int pv=findParent(v,parent); // pv is parent of v
        if(pu==pv)return; // agar dono ka parent same hai toh return karo

        // size compare kyu kya ?
        // kyuki jiska email jyada hai uska size jyada hoga toh usko ultimate parent banana chahiye
        // kyuki ultimate parent k size mei sabka size add hota hai
        if(size[pu]<size[pv]) // agar pu ka size chota hai toh pu ko pv k parent bana do aur size of pv ko pu k size se add kar do
        {
            parent[pu]=pv; // pu ka parent pv
            size[pv]+=size[pu]; // pv ka size pu k size se add kar do
        }
        else // agar pv ka size chota hai, toh pv ko pu k parent bana do aur size of pu ko pv k size se add kar do
        {
            parent[pv]=pu; // pv ka parent pu
            size[pu]+=size[pv]; // pu ka size pv k size se add kar do
        } 
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)  // ye tumhara main function hai jisme tum accounts vector pass karo aur ye tumhe ultimate parent dega
    {
        int n=accounts.size(); // n is number of accounts
        vector<int> parent(n+1); // parent vector declare karo
        for(int i=0;i<n+1;i++) // parent vector ko initialize karo
        {
            parent[i]=i; // parent of i is i kyuki initially sabka parent khud hi hai
        }
        vector<int> size(n+1,1); // size vector declare karo aur initialize karo kyuki initially sabka size 1 hai
        
        unordered_map<string,int> mp; // map declare karo jisme string aur int hoga
        
        for(int i=0;i<n;i++) // saare accounts k liye loop chalao
        {
            for(int j=1;j<accounts[i].size();j++) // saare emails k liye loop chalao
            {
                if(mp.find(accounts[i][j])==mp.end()) // agar map mei nahi hai toh map mei daalo
                {
                    mp[accounts[i][j]]=i; // map mei daalo
                }
                else // agar map mei hai toh union find kardo
                {
                    unionFind(i,mp[accounts[i][j]],parent,size); // union find kardo
                }
                
            }
        }

        vector<vector<string>> ans; // ans vector declare karo
        unordered_map<int,vector<string>> mp1; // map declare karo jisme int aur vector<string> hoga
        for(auto x:mp) // map mei saare elements k liye loop chalao
        {
            int pu=findParent(x.second,parent); // pu is parent of x.second
            mp1[pu].push_back(x.first); // map mei daalo
        }
        for(auto x:mp1) // map mei saare elements k liye loop chalao
        {
            vector<string> temp; // temp vector declare karo
            temp.push_back(accounts[x.first][0]); // temp mei daalo
            sort(x.second.begin(),x.second.end()); // sort kardo
            for(int i=0;i<x.second.size();i++) // x.second k saare elements k liye loop chalao
            {
                temp.push_back(x.second[i]); // temp mei daalo
            }
            ans.push_back(temp); // ans mei daalo
        }
        return ans; // ans return karo
    }

    // iss algorithm ka time complexity O(nlogn) hai aur space complexity O(n) hai
};
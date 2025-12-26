#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Twitter {
public:
    vector<vector<pair<int, int>>>posts;
    vector<vector<bool>>users;
    int time;
    Twitter() {
        time = 0;
        posts.resize(501);
        users.resize(501, vector<bool>(501, 0));
        for(int i = 1; i < 501; i++){
            users[i][i] = 1;
        }
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        posts[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i = 1; i <= 500; i++){
            if(users[userId][i] != 0){
                for(auto post : posts[i]){
                    pq.push(post);
                    if(pq.size() > 10){
                        pq.pop();
                    }
                }
            }
        }
        int cnt = 0;
        while(!pq.empty() && cnt != 10){
            res.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId][followeeId] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
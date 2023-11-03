class Twitter:

    def __init__(self):
        self.followerMap = defaultdict(set)
        self.tweetMap = defaultdict(list)
        self.time = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.time += 1
        self.tweetMap[userId].append([tweetId, -self.time])
        self.followerMap[userId].add(userId)

    def getNewsFeed(self, userId: int) -> List[int]:
        maxHeap = []
        heapq.heapify(maxHeap)

        for followee in self.followerMap[userId]:
            tweets = self.tweetMap[followee]
            index_of_last_tweet = len(tweets) - 1

            if index_of_last_tweet >= 0:
                heapq.heappush(maxHeap, [tweets[index_of_last_tweet][1], tweets[index_of_last_tweet][0], followee, index_of_last_tweet])

        res = []

        # print (maxHeap)

        while maxHeap and len(res) < 10:
            count, tweetId, followee, index = heapq.heappop(maxHeap)
            tweets = self.tweetMap[followee]
            res.append(tweetId)

            if index > 0:
                heapq.heappush(maxHeap, [tweets[index-1][1], tweets[index-1][0], followee, index-1])

        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followerMap[followerId].add(followeeId)
        self.followerMap[followerId].add(followerId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followerMap[followerId]:
            self.followerMap[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
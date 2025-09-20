class Solution:
    def mostPopularCreator(self, creators: List[str], ids: List[str], views: List[int]) -> List[List[str]]:
        n = len(creators)
        creator_views = defaultdict(int)  # Store total video views for each creator
        creator_hot_video = dict()  # Store the video with highest views for each creator in format (video, views)
        for i in range(n):
            creator_name = creators[i]  # Get creator name
            creator_views[creator_name] += views[i]  # Add views to creator's total views
            # For each video, there are 3 cases that we can treat this is the highest views video of its creator
            # 1. There are not any video exist for this creator yet
            # 2. Views of this video is higher than the last highest views video of this creator
            # 3. Views equals to the last highest views video but the id is smaller (lexicographically order)
            if creators[i] not in creator_hot_video or \
                    views[i] > creator_hot_video[creator_name][1] or \
                    (views[i] == creator_hot_video[creator_name][1] and \
                        ids[i] < creator_hot_video[creator_name][0]):
                creator_hot_video[creator_name] = (ids[i], views[i])

        highest_views = max(creator_views.values())  # Get the highest total views of all creators
        # Find all creators who have total views equals to the highest views
        best_creators = [creator for creator in creator_views if creator_views[creator] == highest_views]
        # Return the creators with their best video
        return [[creator, creator_hot_video[creator][0]] for creator in best_creators]
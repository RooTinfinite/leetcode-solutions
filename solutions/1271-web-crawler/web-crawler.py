class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:

        seen = set()
        targetHostname = self.getHostname(startUrl)

        def dfs(url: str) -> None:

            if url in seen:
                return

            if self.getHostname(url) != targetHostname:
                return

            seen.add(url)

            for nei in htmlParser.getUrls(url):
                dfs(nei)

        dfs(startUrl)

        return list(seen)

    def getHostname(self, url: str) -> str:
        return url.split("://")[-1].split("/")[0]
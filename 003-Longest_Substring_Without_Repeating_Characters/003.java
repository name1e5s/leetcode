// Runtime: 24 ms, faster than 77.35% of Java online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 38.9 MB, less than 28.10% of Java online submissions for Longest Substring Without Repeating Characters.
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0)
            return 0;
        int length = 0;
        Queue<Character> queue = new LinkedList<>();
        for(char c : s.toCharArray()) {
            while(queue.contains(c)) {
                queue.poll();
            }
            queue.offer(c);
            length = Math.max(length,queue.size());
        }
    return length;
    }
}
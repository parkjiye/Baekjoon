class Solution {
    public int solution(int n) {
        StringBuilder sb = new StringBuilder();
        sb.append(Integer.toString(n, 3));
        sb.reverse();
        return Integer.parseInt(sb.toString(), 3);
    }
}
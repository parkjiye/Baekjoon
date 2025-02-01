import java.util.*;

class Solution {
    private String[] vowel = {"A", "E", "I", "O", "U"};
    private static List<String> mylist = new ArrayList<>();
    
    private void makeDict(String s, int idx) {
        if(idx==4) {
            for(int i=0;i<5;i++) {
                String tmp = s+vowel[i];
                mylist.add(tmp);
            }
        }
        else {
            for(int i=0;i<5;i++) {
                String tmp = s+vowel[i];
                mylist.add(tmp);
                makeDict(tmp, idx+1);
            }
        }
    }
    
    public int solution(String word) {
        makeDict("", 0);
        return mylist.indexOf(word)+1;
    }
}
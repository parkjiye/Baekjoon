class Solution {
    public String solution(String new_id) {
        
        //1단계 소문자 치환
        new_id = new_id.toLowerCase();
        
        //2단계 특정 문자 제거
        new_id = new_id.replaceAll("[^a-z0-9\\-_.]", "");
        
        //3단계 마침표가 2번 이상 연속된 부분을 하나의 마침표로 치환
        new_id = new_id.replaceAll("\\.+", ".");
        
        //4단계 마침표가 처음이나 끝에 위치한다면 제거
        new_id = new_id.replaceAll("^\\.+|\\.+$", "");
        
        //5단계
        if(new_id.isEmpty()) new_id="a";
        
        //6단계
        if(new_id.length()>=16) {
            new_id = new_id.substring(0, 15);
            new_id = new_id.replaceAll("\\.+$", "");
        }
        
        //7단계
        while(new_id.length()<3){
            new_id+=new_id.charAt(new_id.length()-1);
        }
        
        return new_id;
    }
}
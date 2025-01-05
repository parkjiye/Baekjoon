import java.util.*;

class Solution {
    public int width;
    public int height;
    public long mx = Long.MIN_VALUE;
    public long my = Long.MIN_VALUE;
    public long nx = Long.MAX_VALUE;
    public long ny = Long.MAX_VALUE;
    
    class star {
        public long x, y;
        
        public star(long x, long y){
            this.x = x;
            this.y = y;
        }
    
    
    }
    
    public star makestar(double x1, double x2, double y1, double y2, double z1, double z2){
            double x = (double) (((y1*z2) - (z1*y2)) / ((x1*y2)-(y1*x2)));
            double y = (double) (((z1*x2) - (x1*z2)) / ((x1*y2)-(y1*x2)));
            
            if(x % 1 == 0.0 && y % 1 == 0.0){
                star s = new star((long)x, (long)y);
                return s;
            }
            else {
                return null;
            }
        }
    
    public void calculate(ArrayList<star> stars){
       
        for(star s: stars){
            if(s.x>mx) mx = s.x;
            if(s.y>my) my = s.y;
        }
            
        for(star s: stars){
            if(s.x<nx) nx = s.x;
            if(s.y<ny) ny = s.y;
        }
            
        width = (int) (mx - nx)+1;
        height = (int) (my - ny)+1;
    }
    
    public String[] solution(int[][] line) {
        ArrayList<star> stars = new ArrayList<>();
        
        for(int i=0;i<line.length;i++){
            for(int j=i+1;j<line.length;j++){
                if(line[i][0]*line[j][1]==line[i][1]*line[j][0]) continue;
                star s = makestar(line[i][0], line[j][0], line[i][1], line[j][1], line[i][2], line[j][2]);
                
                if(s==null) continue;
                stars.add(s);

            }
        }
        
        calculate(stars);
    
        char[][] sky = new char[height][width];
        for(char[] row:sky) {
            Arrays.fill(row, '.');
        }
        
        for(star s: stars){
            sky[(int)(my-s.y)][(int)(s.x-nx)]='*';
        }
        
        String[] answer = new String[sky.length];
        for(int i=0;i<answer.length;i++){
            answer[i]=new String(sky[i]);
        }
        
        
        return answer;
    }
}
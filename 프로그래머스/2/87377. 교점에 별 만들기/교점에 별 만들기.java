import java.util.List;
import java.util.ArrayList;
import java.util.*;

class Solution {
    
    public static class Point {
        private final long x, y;
        
        private Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }
    
    public Point intersection(long a1, long b1, long c1, long a2, long b2, long c2) {
        double x = (double)(b1*c2 - c1*b2) / (a1*b2-b1*a2);
        double y = (double) (c1*a2-a1*c2) / (a1*b2-b1*a2);
        
        if(x%1!=0 || y%1!=0)
        {
            return null;
        }
        
        
        return new Point((long)x, (long)y);
    }
    
    public Point getMaxPoint(List<Point> points) {
        long x = Long.MIN_VALUE;
        long y = Long.MIN_VALUE;
        
        for(Point p:points)
        {
            if(p.x>x) x = p.x;
            if(p.y>y) y = p.y;
        }
        
        return new Point(x,y);
        
    }
    
    public Point getMinPoint(List<Point> points) {
        long x = Long.MAX_VALUE;
        long y = Long.MAX_VALUE;
        
        for(Point p : points)
        {
            if(p.x<x)x=p.x;
            if(p.y<y)y=p.y;
        }
        
        return new Point(x,y);
    }
    
    public String[] solution(int[][] line) {
        String[] answer = {};
        
        List<Point> points = new ArrayList<>();
        
        for(int i=0;i<line.length;i++)
        {
            for(int j=i+1;j<line.length;j++)
            {
                Point temp = intersection(line[i][0], line[i][1], line[i][2], line[j][0], line[j][1], line[j][2]);
                
                if(temp!=null)
                {
                    points.add(temp);
                }
            }
        }
        
        Point maxPoint = getMaxPoint(points);
        Point minPoint = getMinPoint(points);
        
        long width = maxPoint.x-minPoint.x+1;
        long height = maxPoint.y-minPoint.y+1;
        
        answer=new String[(int)height];
        
        for(int i=0;i<height;i++)
        {
            String sen="";
            for(int j=0;j<width;j++)
            {
                sen+='.';
            }
            answer[i]=sen;
        }
        
        for(Point p:points)
        {
            //System.out.println(p.x+" "+p.y);
                
            if(p.x>=minPoint.x && p.y>=minPoint.y && p.x<=maxPoint.x && p.y<=maxPoint.y)
            {
                Point cur = new Point(maxPoint.y-p.y, p.x-minPoint.x);          
                
                //System.out.println(cur.x + " "+cur.y);
                String temp = answer[(int)cur.x];
                answer[(int)cur.x]= temp.substring(0, (int)(cur.y))+'*'+temp.substring((int)(cur.y)+1);
            }
        }
        
        
        return answer;
    }
}
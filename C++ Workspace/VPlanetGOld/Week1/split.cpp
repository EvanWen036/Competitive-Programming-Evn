import java.io.*;
import java.util.*;
public class Open1Gold16 {
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    static BufferedReader sc;
    static StringTokenizer st = new StringTokenizer("");
    static {

        try {
            sc = new BufferedReader(new InputStreamReader(System.in));
        }
        catch(Exception e){

        }
    }
    static void check() throws Exception {
        while (!st.hasMoreTokens()) st = new StringTokenizer(sc.readLine());
    }
    static String s() throws Exception { check(); return st.nextToken(); }
    static int i() throws Exception { return Integer.parseInt(s()); }
    static long l() throws Exception { return Long.parseLong(s()); }
    static double d() throws Exception { return Double.parseDouble(s()); }

    static class Point implements Comparable<Point>{
        long x;
        long y;
        public Point(long a, long b){
            x = a;
            y =b;
        }
        public int compareTo(Point p){
            if(x < p.x){
                return -1;
            }
            if(p.x < x){
                return 1;
            }
            return 0;
        }
    }

    public static void main(String[] args) throws Exception {
        sc = new BufferedReader(new FileReader("split.in"));
        out = new PrintWriter(new FileWriter("split.out"));
        int N = i();
        Point[] p = new Point[N];
        for(int i = 0; i < N; i++){
            p[i] = new Point(i(), i());
        }
        Arrays.sort(p);
        TreeSet<Long> yVals = new TreeSet<Long>();
        long[] leftArea = new long[N];
        for(int i = 0; i < N; i++){
            yVals.add(p[i].y);
            long area = (yVals.last() - yVals.first()) * (p[i].x - p[0].x);
            leftArea[i] = area;
        }
        TreeSet<Long> yVals2 = new TreeSet<Long>();
        long[] rightArea = new long[N];
        for(int i = N-1; i>= 0; i--){
            long area = 0;
            if(yVals2.size() != 0) {
                area = (yVals2.last() - yVals2.first()) * (p[N-1].x - p[i+1].x);
            }
            yVals2.add(p[i].y);
            rightArea[i] = area;
        }
        long normArea = (yVals.last() - yVals.first())*(p[N-1].x - p[0].x);
        long ans = 0;
        for(int i = 0; i < N;i ++){
            ans = Math.max(ans, normArea - (leftArea[i] + rightArea[i]));
        }
        for(int i = 0 ;i < N; i++){
            long y = p[i].y;
            p[i].y = p[i].x;
            p[i].x = y;
        }
        Arrays.sort(p);
        yVals = new TreeSet<Long>();
        leftArea = new long[N];
        for(int i = 0; i < N; i++){
            yVals.add(p[i].y);
            long area = (yVals.last() - yVals.first()) * (p[i].x - p[0].x);
            leftArea[i] = area;
        }
        yVals2 = new TreeSet<Long>();
        rightArea = new long[N];
        for(int i = N-1; i>= 0; i--){
            long area = 0;
            if(yVals2.size() != 0) {
                area = (yVals2.last() - yVals2.first()) * (p[N-1].x - p[i+1].x);
            }
            yVals2.add(p[i].y);
            rightArea[i] = area;
        }
        normArea = (yVals.last() - yVals.first())*(p[N-1].x - p[0].x);
        for(int i = 0; i < N;i ++){
            ans = Math.max(ans, normArea - (leftArea[i] + rightArea[i]));
        }
        out.println(ans);
        out.close();
    }
}

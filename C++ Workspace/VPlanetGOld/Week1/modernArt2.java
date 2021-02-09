import java.io.*;
import java.util.*;
public class Open3Gold17 {
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
    static class Event implements Comparable<Event>{
        int x;
        int y;
        int c;
        public Event(int a, int b, int c){
            x = a;
            y = b;
            this.c =c;
        }
        public int compareTo(Event e){
            return x - e.x;
        }
    }
    public static void main(String[] args) throws Exception{
    
        int N= i();
        int[] A = new int[N];
        int[] lastSeen = new int[N+1];
        int[] firstSeen = new int[N+1];
        Arrays.fill(firstSeen, -1);
        ArrayList<Event> e = new ArrayList<Event>();
        for(int i = 0; i < N; i++){
            A[i] = i();
            if(A[i] == 0)continue;
            lastSeen[A[i]] = i;
            firstSeen[A[i]] = firstSeen[A[i]] == -1 ? i : firstSeen[A[i]];
        }

        for(int i = 1; i <= N; i++){
            if(firstSeen[i] == -1)continue;
            e.add(new Event(firstSeen[i], lastSeen[i], i));
        }
        long[] prefix = new long[N+5];
        for(int i = 1; i <= N;i ++){
            if(firstSeen[i] == -1)continue;
            prefix[firstSeen[i]]++;
            prefix[lastSeen[i]+1]--;
        }
        long[] real = new long[N+5];
        long max = 0;
        for(int i = 0; i < N; i++){
            real[i] += prefix[i];
            if(i != 0){
                real[i] += real[i-1];
            }
            max = Math.max(max, real[i]);
        }
	    int maxEnd = -1;
        //test to see if legit painting
	    for(int i = 0; i < N;i ++){
	        if(i == firstSeen[A[i]] ){
               if(i < maxEnd && lastSeen[A[i]] > maxEnd){
	                max = -1;
                    break;
               }
               maxEnd = Math.max(maxEnd, lastSeen[A[i]]);
            }
	    }
        out.println(max);
        out.close();
    }
}

import java.io.*;
import java.util.*;
public class Prob01{

  public static void main(String[] args) throws IOException{
    Scanner scan = new Scanner(System.in);
    PrintWriter out = new PrintWriter(new FileWriter("Prob01.out.txt"));
    //Scanner scan = new Scanner(new File(args[0] + "Prob01.in.txt"));
    int t = Integer.parseInt(scan.nextLine());
    while(t > 0){
      int n = Integer.parseInt(scan.nextLine());
      for(int i = 0; i < n;i ++){
        String line = scan.nextLine();
        line = line.toUpperCase();
        String[] parts = line.split(" ");
        out.println(parts[0].substring(0,1) + parts[2].substring(0,1) + parts[1].substring(0,1));
      }
      t--;
    }
    out.close();

  }
}

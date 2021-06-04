import java.io.*;
import java.util.*;
public class Prob10{
  public static void main(String[] args) throws IOException{
    Scanner scan = new Scanner(System.in);
    PrintWriter out = new PrintWriter(new FileWriter("Prob10.out.txt"));
    String[] scores = new String[] {"love", "15", "30", "40"};
    int[] ppl = new int[] {0,0,0};
    int adv = -1;
    boolean deuce = false;
    out.println("Game start");
    while(true){
      String line = scan.nextLine();
      if(line.equals(""))break;
      int curP = Integer.parseInt(line);
      if(!deuce){
        if(ppl[curP] != 3){
          ppl[curP]++;
          if(ppl[1] == 3 && ppl[2] == 3){
            deuce = true;
            out.println("deuce");
          }
          else if(ppl[1] == ppl[2]){
            out.println(scores[ppl[1]] + "-all");
          }

          else{
            out.println(scores[ppl[1]] + "-" + scores[ppl[2]]);
          }
        }
        else{
          ppl[1] = 0;
          ppl[2] = 0;
          out.println("Game Player " + curP);
          out.println("Game start");

        }
      }
      else if(deuce){
        if(adv == curP){
          ppl[1]=0;
          ppl[2]=0;
          deuce=false;
          adv = -1;
          out.println("Game Player " + curP);
          out.println("Game start");

        }
        else if(adv == -1){
          adv = curP;
          out.println("Advantage Player " + curP);
        }
        else{
          adv = -1;
          out.println("deuce");
        }
      }

    }
    out.close();
  }
}

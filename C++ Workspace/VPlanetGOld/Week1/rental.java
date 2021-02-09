import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class rental {
    static class offers{
        int gallons;
        int price;
    }
    static class Compare implements Comparator<offers>{
        public int compare(offers a, offers b){
            return b.price-a.price;
        }
    }

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new FileReader("rental.in"));
        PrintWriter out = new PrintWriter(new FileWriter("rental.out"));

        int N = sc.nextInt();
        int M = sc.nextInt();
        int R = sc.nextInt();
        Integer[] amounts = new Integer[N];
        for(int i = 0 ; i< N ;i++){
            amounts[i] = sc.nextInt();
        }
        Arrays.sort(amounts, Collections.reverseOrder());
        ArrayList<offers> offers = new ArrayList<offers>();
        for(int i = 0; i < M; i++){

            offers offer = new offers();
            offer.gallons = sc.nextInt();
            offer.price= sc.nextInt();
            offers.add(offer);
        }
        Collections.sort(offers, new Compare());
        Integer[] rentals = new Integer[R];
        for(int i =0; i < R;i ++){

            rentals[i] = sc.nextInt();
        }
        Arrays.sort(rentals, Collections.reverseOrder());

        //System.out.println(amounts.toString());
        //System.out.println(rentals.toString());
        long[] milkedFor = new long[N];
        int index = 0;
        for(int i = 0; i < N; i++){
            long sum = 0;
            if(offers.size()== 0){
                break;
            }
            if(offers.get(index).gallons >= amounts[i]){
               sum += amounts[i] * offers.get(index).price;
               offers.get(index).gallons -= amounts[i];
               if(offers.get(index).gallons == 0){

                   offers.remove(0);
                   if(offers.size() == 0){
                       break;
                   }

               }

               milkedFor[i] = sum;
               continue;
            }
            if(offers.size() > 0 && offers.get(index).gallons < amounts[i]){
                sum += (amounts[i] - offers.get(index).gallons) * (offers.get(index).price);
                amounts[i] -= offers.get(index).gallons;
                offers.remove(0);
                while(offers.size() > 0 && amounts[i] > 0){

                    if(amounts[i] > offers.get(index).gallons){

                        sum += (amounts[i] - offers.get(index).gallons) * (offers.get(index).price);
                        amounts[i] -= offers.get(index).gallons;
                        offers.remove(0);
                        if(offers.size() == 0){
                            break;
                        }

                    }
                    else{

                        sum += (amounts[i]) * offers.get(index).price;
                        offers.get(index).gallons -= amounts[i];
                        if(offers.get(index).gallons == 0){
                            offers.remove(0);
                            if(offers.size() == 0){
                                break;
                            }
                        }
                        break;
                    }

                }

            }
            milkedFor[i] = sum;

        }
        Arrays.sort(milkedFor);
        int rentalsInd = 0;
        for(int i = 0; i < N; i++){
            if(rentalsInd >= R || milkedFor[i] > rentals[rentalsInd]){
                break;
            }

            if(milkedFor[i] < rentals[rentalsInd]){
                milkedFor[i] = rentals[rentalsInd];
                rentalsInd++;
            }

        }
        long sum = 0;
        for(int i =0 ; i < N; i++){
            sum += milkedFor[i];
        }

        out.println(sum);
        out.close();

    }
}

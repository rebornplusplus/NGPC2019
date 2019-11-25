import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.Math.min;

public class Unnamed {

    private static final int mod = 1000000007;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        assert (n>=1 && n<=100000);
        List<Integer> ar = new ArrayList<>();
        List<Integer> dp = new ArrayList<>();
//        List<Integer> e = new ArrayList<>();

        for(int i=0; i<n; i++) {
            int x = sc.nextInt();
            ar.add(x);
            dp.add(0);
            assert (x>=1 && x<=1000000);
//            e.add(0);
        }
        dp.add(0);
        dp.add(0);
//        e.add(0);
//        e.add(0);

        for(int i=n-1; i>=0; i--) {
            int sq = (int) Math.sqrt(ar.get(i));
            sq++;
            if(sq*sq > ar.get(i)) sq--;

            for(int j=1; j<=n && j<=sq; j++) {
                if(ar.get(i)%j == 0) {
//                    e.set(j, e.get(j)+1);
                    dp.set(j, (dp.get(j+1)+dp.get(j)+1)%mod);
//                    System.out.println(i + " " + j + " " + e.get(j) + " " + dp.get(j));
                }
            }
            for(int j= sq; j>0; j--) {
                if(ar.get(i)%j == 0) {
                    int k = ar.get(i)/j;
                    if(k>n || k == j) continue;
//                    e.set(k, e.get(k)+1);
                    dp.set(k, (dp.get(k+1)+dp.get(k) +1)%mod);
//                    System.out.println(i + " " + k + " " + e.get(k) + " " + dp.get(k));
                }
            }
        }
//        System.out.println(dp.toString());
        System.out.println(dp.get(1));
    }
}

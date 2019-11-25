import java.math.BigInteger;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;
import java.util.Scanner;

public class Unnamed {

    private static long p;
    private static long mod = 1000000007;
    private static final BigInteger TWO = BigInteger.ONE.add(BigInteger.ONE);
    private static Pair<Long, Long> BASE_PAIR;

    private static Pair<Long, Long> mul(Pair<Long, Long> p1, Pair<Long, Long> p2, long l) {

        long first = p1.getKey()*p2.getKey();
        first %= mod;
        first *= l;
        first %= mod;
        first += p1.getKey()*p2.getValue();
        first %= mod;
        first += p2.getKey()*p1.getValue();
        first %= mod;
        first += (p1.getValue()*p2.getValue())/l;
        first %= mod;

        long second = (p1.getValue()*p2.getValue())%l;
        return new Pair<>(first, second);
    }

    private static Pair<Long, Long> div(long d, long l) {
        if(d == 1) {
            return BASE_PAIR;
        }

        Pair<Long, Long> p1, p2;
        p1 = div(d/2, l);
        p2 = mul(p1, p1, l);
        if(d%2 == 1) {
            p2 = mul(p2, BASE_PAIR, l);
        }
        return p2;
    }

    private static long gcd(long a, long b) {
        if(b>a) return gcd(b,a);
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    private static long LCM(long a, long b) {
        return (a*b)/gcd(a,b);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        BigInteger lim = BigInteger.TEN.pow(100000);

        int t = sc.nextInt();
        assert (t>=1 && t<=100000);
        int cs = 1;
        while (t-- > 0) {

            BigInteger n = sc.nextBigInteger();
            p = sc.nextLong();

            assert (n.compareTo(BigInteger.ONE)>=0 && n.compareTo(lim)<=0);
            assert (p>=1 && p<=100000);

            int s = sc.nextInt();
            assert (s>=1 && s<=5);
            List<Long> list = new ArrayList<>();

            for(int i=0; i<s; i++) {
                long l = sc.nextLong();
                assert (l>=1 && l<=1000000000);
                list.add(l);
            }

            long ans = 0;

            for(int i=1; i<(1<<s); i++) {
                BitSet set = BitSet.valueOf(new long[]{i});

                long lcm = 1;
                for(int j=0; j<s; j++) {
                    if(set.get(j)) lcm = LCM(lcm, list.get(j));
                }
                BigInteger[] temp = n.divideAndRemainder(BigInteger.valueOf(lcm));
                BASE_PAIR = new Pair<>(temp[0].mod(BigInteger.valueOf(mod)).longValue(),
                        temp[1].mod(BigInteger.valueOf(mod)).longValue());
                if(set.cardinality()%2==0) {
                    ans -= div(p, lcm).getKey();
                } else {
                    ans += div(p, lcm).getKey();
                }
                ans %= mod;
            }
            if(ans< 0) ans+= mod;
            System.out.println("Case " + cs + ": " + ans);
            cs++;
        }
    }


    private static class Pair<L,K> {

        private L first;
        private K second;

        private Pair(L first, K second) {
            this.first = first;
            this.second = second;
        }

        private L getKey() {
            return first;
        }
        private K getValue() {
            return second;
        }
    }
}

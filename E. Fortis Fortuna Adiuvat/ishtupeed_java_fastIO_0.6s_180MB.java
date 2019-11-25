import java.io.BufferedInputStream;
import java.io.InputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.PriorityQueue;


public class Unnamed
{
    int maxN = 100005;
    List<List<Node> >g1;
    List<List<Node> >g2;
    long[] dist1;
    long[] dist2;
    long maxVal = 1000000000000000000L;

    void initGraph(int n)
    {
        g1 = new ArrayList<List<Node> >();
        g2 = new ArrayList<List<Node> >();
        for (int i = 1; i < n + 5; i++)
        { 
            List<Node> item = new ArrayList<Node>(); 
            g1.add(item);
        } 
        for (int i = 0; i < n + 5; i++)
        { 
            List<Node> item = new ArrayList<Node>(); 
            g2.add(item);
        } 
        Arrays.fill(dist1, maxVal);
        Arrays.fill(dist2, maxVal);
    }

    void dijkstra1(int source)
    {
        // System.out.println("Dijkstra1");
        // System.out.println("g1 size() = "+g1.size());
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(source, Long.valueOf(0)));
        dist1[source] = 0;
        int u, sz, v;
        long uw, vw, cost;
        while(pq.size()!=0)
        {
            Node n = pq.poll();
            u = n.f();
            uw = n.s();
            // System.out.println("Got node"+u);
            if(uw != dist1[u])
                continue;
            sz = g1.get(u).size();
            for(int i = 0; i < sz; i++)
            {
                Node m = g1.get(u).get(i);
                v = m.f();
                vw = m.s();
                cost = dist1[u] + vw;
                if(dist1[v] > cost)
                {
                    dist1[v] = cost;
                    pq.add(new Node(v, cost));
                }
            }
        }
    }

    void dijkstra2(int source)
    {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(source, Long.valueOf(0)));
        dist2[source] = 0;
        int u, sz, v;
        long uw, vw, cost;
        while(pq.size()!=0)
        {
            Node n = pq.poll();
            u = n.f();
            uw = n.s();
            if(uw != dist2[u])
                continue;
            sz = g2.get(u).size();
            for(int i = 0; i < sz; i++)
            {
                Node m = g2.get(u).get(i);
                v = m.f();
                vw = m.s();
                cost = dist2[u] + vw;
                if(dist2[v] > cost)
                {
                    dist2[v] = cost;
                    pq.add(new Node(v, cost));
                }
            }
        }
    }

    void solve() throws IOException
    {
        dist1 = new long[maxN];
        dist2 = new long[maxN];
        Reader cin = new Reader();
        Print cout = new Print();
        int T, N, M, x, Q, u, v, s, t;
        int cases = 1;
        long ans, w;
        T = cin.nextInt();
        while(T != 0)
        {
            T--;
            N = cin.nextInt();
            M = cin.nextInt();
            x = cin.nextInt();
            Q = cin.nextInt();
            initGraph(N);
            while(M != 0)
            {
                M--;
                u = cin.nextInt();
                v = cin.nextInt();
                w = cin.nextLong();

                g1.get(u).add(new Node(v, w));
                g2.get(v).add(new Node(u, w));
            }
            dijkstra1(x);
            dijkstra2(x);
            String c = "Case " + String.valueOf(cases) + ":";
            cout.printLine(c);
            cases++;
            while(Q != 0)
            {
                Q--;
                s = cin.nextInt();
                t = cin.nextInt();
                ans = dist2[s] + dist1[t];
                if(ans >= 10000000000000000L)
                {
                    cout.printLine("Be seeing ya, John");
                }
                else
                {
                    String res = String.valueOf(ans);
                    cout.printLine(res);
                }
            }
        }
        cout.close();
    }


    public static void main(String[] args)
    {
        try 
        {
            new Unnamed().solve();
        } 
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Node class for storing node name and weight
    public class Node implements Comparable<Node>
    {
        private int name;
        private long weight;

        public Node(int n, Long w)
        {
            this.name = n;
            this.weight = w;
        }

        public int f()
        {
            return name;
        }

        public long s()
        {
            return weight;
        }

        @Override
        public int compareTo(Node other)
        {
            long a = this.s();
            long b = other.s();
            if(a < b)
                return -1;
            if(a == b)
                return 0;
            return 1;
        }
    }

    // JAVA FAST IO
    static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 

        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 

        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 

        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; // line length 
            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 

        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 

            if (neg) 
                return -ret; 
            return ret; 
        } 

        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 

        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 

            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 

            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 

            if (neg) 
                return -ret; 
            return ret; 
        } 

        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 

        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 

        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        }
    }

    class Print
    {
        private final BufferedWriter bw;
        public Print()
        {
            bw=new BufferedWriter(new OutputStreamWriter(System.out));
        }
        public void print(String str)throws IOException
        {
            bw.append(str);
        }
        public void printLine(String str)throws IOException
        {
            print(str);
            bw.append("\n");
        }
        public void close()throws IOException
        {
            bw.close();
        }
    }
}

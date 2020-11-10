import java.util.*;

public class Main {
    
	public static void main(String[] args) {
	    Scanner input = new Scanner(System.in);
	    long INF = 1000000000000L;
	    String[] nm = input.nextLine().split(" ");
		int n = Integer.parseInt(nm[0]);
		int m = Integer.parseInt(nm[1]);
		
		long[] d = new long[n+1];
		int[] pre = new int[n+1];
		for(int i =0; i <= n; i++) {
			d[i] = INF;
			pre[i] = 0;
		}
		
		ArrayList < ArrayList<Pair> > g = new ArrayList< ArrayList<Pair> >();	//lista de adjacencias
		for(int i =0; i <= n; i++) {
			g.add(new ArrayList<Pair>());
		}
		for(int i = 0; i < m; i++) {
		    String[] edge = input.nextLine().split(" ");
			int v = Integer.parseInt(edge[0]);
			int u = Integer.parseInt(edge[1]);
			long w = Long.parseLong(edge[2]);
			g.get(v).add(new Pair(u,w));
			g.get(u).add(new Pair(v,w));
		}
		
		//Dijkstra (só essas 14 linhas)
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		d[1] = 0;
		pq.add(new Pair(0, 1));
		while(pq.size() != 0) {
		    Pair p = pq.poll();
		    if (p.first > d[(int)p.second]) continue;
		    for (Pair adj : g.get((int)p.second)) {
		        if (p.first+adj.second < d[(int)adj.first]) {
		            d[(int)adj.first] = p.first+adj.second;
		            pq.add(new Pair(d[(int)adj.first], adj.first));
		            pre[(int)adj.first] = (int)p.second;
		        }
		    }
		}
		
		//Printa resposta
		
		if (pre[n] == 0) {
		    System.out.println("-1");
		} else {
		    ArrayList<Integer> resp = new ArrayList();
		    while(n != 0) {
		        resp.add(n);
		        n = pre[n];
		    }
		    for(int i = resp.size()-1; i >= 0; i--) {
		        if (i != resp.size()-1) System.out.print(" ");
		        System.out.print(resp.get(i));
		    }
		}
	
	}
	
	static class Pair implements Comparable<Pair> {
    	public long first;
    	public long second;
    	
    	public Pair(long v1, long v2) {
    		first = v1;
    		second = v2;
    	}
    	public int compareTo(Pair o) {
            if (first != o.first) {
                if (first < o.first) return -1;
                else return 1;
            }
            if (second != o.second) {
                if (second < o.second) return -1;
                else return 1;
            }
            return 0;
        }
    }
}

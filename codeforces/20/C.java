import java.util.*;

public class Main {
    public static long infinity = 1000000000000L;
    public static int n, m;
	public static void main(String[] args) {
	    Scanner input = new Scanner(System.in);
		String[] nm = input.nextLine().split(" ");
		n = Integer.parseInt(nm[0]);
		m = Integer.parseInt(nm[1]);
		
		long[] distances = new long[n+1];
		int[] predecessors = new int[n+1];
		for(int i =0; i < distances.length; i++) {
			distances[i] = infinity;
			predecessors[i] = 0;
		}
		
		ArrayList < ArrayList<Pair> > graph = new ArrayList< ArrayList<Pair> >();	//lista de adjacencias
		for(int i =0; i <= n; i++) {
			graph.add(new ArrayList<Pair>());
		}
		for(int i = 0; i < m; i++) {
			String[] edges = input.nextLine().split(" ");
			int v1 = Integer.parseInt(edges[0]);
			int v2 = Integer.parseInt(edges[1]);
			long w = Long.parseLong(edges[2]);
			graph.get(v1).add(new Pair(v2,w));
			graph.get(v2).add(new Pair(v1,w));
		}
		dijkstra(distances, graph, predecessors, 1);
		System.out.println(restorePath(1,n,predecessors));
	}

	private static void dijkstra(long[] distances, ArrayList < ArrayList<Pair> > graph, int[] predecessors, int start) {
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		distances[start] = 0;
		pq.add(new Pair(0, start));
		while(pq.size() != 0) {
		    Pair p = pq.poll();
		    if (p.first > distances[(int)p.second]) continue;
		    for (Pair adj : graph.get((int)p.second)) {
		        if (p.first+adj.second < distances[(int)adj.first]) {
		            distances[(int)adj.first] = p.first+adj.second;
		            pq.add(new Pair(distances[(int)adj.first], adj.first));
		            predecessors[(int)adj.first] = (int)p.second;
		        }
		    }
		}
	}
	private static String restorePath(int s, int t,int[] predecessors) {
	    if (predecessors[t] == 0) return "-1";
		Stack<Integer> path = new Stack<Integer>();
		for(int v = t; v!=s;v=predecessors[v]) {
			path.add(v);
		}
		path.add(s);
		StringBuilder shortestPath = new StringBuilder();
		shortestPath.append(path.pop());
		while(path.size() != 0) {
		    shortestPath.append(" ");
			shortestPath.append(path.pop());
		}
		return shortestPath.toString();
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

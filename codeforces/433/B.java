import java.util.Scanner;
import java.lang.Math; 
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main{
	public static void main(String args[]) throws IOException {
		//Scanner input = new Scanner(System.in);
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(input.readLine());
		StringTokenizer stonesCosts = new StringTokenizer(input.readLine());
		
		Long[] cumulatedSum = new Long[n];
		Long[] sortedCosts = new Long[n];	
		Long[] sortedCumulatedSum = new Long[n];
		
		Long num = Long.parseLong(stonesCosts.nextToken());
		cumulatedSum[0] = num;//para evitar indexoutofbounds
    sortedCosts[0] = num;
		
		for(int i = 1; i < n;i++){
			num = Long.parseLong(stonesCosts.nextToken());
			cumulatedSum[i] = num + cumulatedSum[i-1];
			sortedCosts[i] = num;
		}
		
		Arrays.sort(sortedCosts);
		sortedCumulatedSum[0] = sortedCosts[0]; //para evitar indexoutofbounds
		for(int i =1; i < n;i++){
			sortedCumulatedSum[i] = sortedCosts[i] + sortedCumulatedSum[i-1];
		}
		
		int m = Integer.parseInt(input.readLine());
		Long[] results = new Long[m];

		for(int i = 1; i<=m; i++){
			StringTokenizer temp = new StringTokenizer(input.readLine());
			int type = Integer.parseInt(temp.nextToken());
			int l = Integer.parseInt(temp.nextToken());
			int r = Integer.parseInt(temp.nextToken());
			
			if(type == 1){ //pergunta 1
				results[i-1] = answerQuestion(l, r, cumulatedSum);
			}else { //pergunta 2
				results[i-1] = answerQuestion(l, r, sortedCumulatedSum);
			}
		}
		for(long result: results){
			System.out.println(result);
		}
	}
	private static Long answerQuestion(int l, int r, Long[] costs){
		
		if((l-2)==-1){//para verificar se não vai dar indexoutofbounds
			return costs[r-1];
		}
		return costs[r-1] - costs[l-2];
	}
}
import java.util.*;

public class Triathlon{

	public static class Runner{
		public int coding;
		public int other;
		public Runner(int a, int b){
		    coding = a;
		    other = b;
		}
	}

	public static void compute(Runner[] runner, int N){
		Arrays.sort(runner, new Comparator<Runner>() {
		    public int compare(Runner o1, Runner o2) {
		        // Intentional: Reverse order for this demo
		        return (o2.other > o1.other) ? 1 : -1;
		    }
		});
        int ans = runner[0].coding + runner[0].other;
        int coding = runner[0].coding;
		for (int i = 1; i < N; i++) {
			System.out.println(runner[i].coding + " " + runner[i].other);
			coding  += runner[i].coding;
			ans = Math.max(temp + runner[i].other);
		}

		System.out.println(ans);
	}

	public static void main(String[] args) {
        
        //Triathlon triathlon = new Triathlon();
		int N;

		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();

		Runner[] runner = new Runner[N];

		for (int i = 0 ; i < N; i++) {
			int a,b,c;
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			runner[i] = new Runner(a, b+c);

		}
		
		compute(runner, N);


		
	}
	
}
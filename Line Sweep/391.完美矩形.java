public class Solution {
	public boolean isRectangleCover(int[][] v) {
		HashSet<String> mp = new HashSet<String>();
		int l = Integer.MAX_VALUE;
		int r = Integer.MIN_VALUE;
		int t = Integer.MIN_VALUE;
		int b = Integer.MAX_VALUE;
		int n = v.length;
		int all = 0;

		for (int i = 0; i < n; ++i){
			l = Math.min(l, v[i][0]);
			b = Math.min(b, v[i][1]);
			r = Math.max(r, v[i][2]);
			t = Math.max(t, v[i][3]);

			all += (v[i][3] - v[i][1]) * (v[i][2] - v[i][0]);

			String lt = v[i][0] + " " + v[i][3];
			String lb = v[i][0] + " " + v[i][1];
			String rt = v[i][2] + " " + v[i][3];
			String rb = v[i][2] + " " + v[i][1];

			if (!mp.contains(lt)) mp.add(lt); else mp.remove(lt);
			if (!mp.contains(lb)) mp.add(lb); else mp.remove(lb);
			if (!mp.contains(rt)) mp.add(rt); else mp.remove(rt);
			if (!mp.contains(rb)) mp.add(rb); else mp.remove(rb);
		}


		if (mp.size() == 4 && 
	            mp.contains(l + " " + t) && 
		    mp.contains(l + " " + b) && 
		    mp.contains(r + " " + b) && 
		    mp.contains(r + " " + t))
		return all == (r - l) * (t - b);

		return false;
	}
}


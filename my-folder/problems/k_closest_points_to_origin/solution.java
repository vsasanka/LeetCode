class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[1]-b[1]);

        for (int i=0; i<points.length; i++){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.add(new int[] {i, dist});
        }

        int[][] res = new int[k][];

        while (k > 0){
            k--;
            res[k] = points[pq.poll()[0]];
        }

        return res;
    }
}
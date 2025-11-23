class Solution {

    private boolean isValid(List<List<Character>> board, int row, int col, int n) {

        // check column
        for (int r = 0; r < row; r++) {
            if (board.get(r).get(col) == 'Q') return false;
        }

        // check left diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if (board.get(r).get(c) == 'Q') return false;
        }

        // check right diagonal
        for (int r = row, c = col; r >= 0 && c < n; r--, c++) {
            if (board.get(r).get(c) == 'Q') return false;
        }

        return true;
    }

    private void dfs(List<List<Character>> board, int[] count, int row, int n) {

        if (row == n) {
            count[0]++;
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isValid(board, row, col, n)) {

                board.get(row).set(col, 'Q');   // choose
                dfs(board, count, row + 1, n);  // explore
                board.get(row).set(col, '.');   // backtrack
            }
        }
    }

    public int totalNQueens(int n) {

        List<List<Character>> board = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            List<Character> row = new ArrayList<>();
            for (int j = 0; j < n; j++) row.add('.');
            board.add(row);
        }

        int[] count = new int[1];
        dfs(board, count, 0, n);

        return count[0];
    }
}

1079. Letter Tile Possibilities

class Solution {
public:
    set<string>s;
    
    int numTilePossibilities(string tiles, string word = "") {
        int n = tiles.length();
        for(int i=0; i<n; i++){
            if(s.find(word+tiles[i]) == s.end()){
                s.insert(word+tiles[i]);
                string tempTiles = tiles.substr(0, i) + tiles.substr(i+1, n-i-1);
                numTilePossibilities(tempTiles, word+tiles[i]);
            }
        }
        
        return s.size();
    }
};

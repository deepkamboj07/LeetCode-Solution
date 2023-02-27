/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* makeQuad(vector<vector<int>> &grid, int sr, int er, int sc, int ec)
    {
        if(sr > er || sc > ec) return NULL;
        
        int val=grid[sr][sc];
        bool same=true;
        for(int i=sr;i<=er;i++)
        {
            for(int j=sc;j<=ec;j++)
            {
                if(grid[i][j]!=val)
                {
                    same=false;
                    break;
                }
            }
            if(!same)break;
        }
        
        if(same)
            return new Node(val,true);
        
        int rowMid= (sr + er)/2;
        int colMid= (sc + ec)/2;
        
        Node* topLeft=makeQuad(grid,sr,rowMid,sc,colMid);
        Node* topRight=makeQuad(grid,sr,rowMid,colMid+1,ec);
        Node* bottomLeft=makeQuad(grid,rowMid+1,er,sc,colMid);
        Node* bottomRight=makeQuad(grid,rowMid+1,er,colMid+1,ec);
        
        return new Node(false,false,topLeft,topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return makeQuad(grid,0,n-1,0,n-1);
    }
};
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ParkingLot {
private:
    struct SegmentTreeNode {
        int left;       
        int right;      
        int max_empty;  
        int left_empty;  
        int right_empty; 
        bool all_empty;  
    };
    vector<SegmentTreeNode> tree;
    vector<bool> slots;
    int n;

    SegmentTreeNode merge(const SegmentTreeNode& l, const SegmentTreeNode& r) {
        SegmentTreeNode res;
        res.left = l.left;
        res.right = r.right;
        res.all_empty = l.all_empty && r.all_empty;
        res.left_empty = l.all_empty ? (l.max_empty + r.left_empty) :l.left_empty; 
        res.right_empty = r.all_empty ?(r.max_empty + l.right_empty):r.right_empty;        
        res.max_empty = max({l.max_empty,r.max_empty,l.right_empty + r.left_empty});
        return res;
    }



    void build(int node, int l, int r) {
        tree[node].left = l;
        tree[node].right = r;
        
        if (l == r) {
            tree[node].max_empty = 1;
            tree[node].left_empty = 1;
            tree[node].right_empty = 1;
            tree[node].all_empty = true;
            return;
        }
        
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
        
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    void update(int node, int pos, bool occupied) {
        if (tree[node].left == tree[node].right) {
            tree[node].max_empty = occupied ? 0 : 1;
            tree[node].left_empty = occupied ? 0 : 1;
            tree[node].right_empty = occupied ? 0 : 1;
            tree[node].all_empty = !occupied;
            return;
        }
        
        int mid = (tree[node].left + tree[node].right) / 2;
        if (pos <= mid) {
            update(2 * node + 1, pos, occupied);
        } else {
            update(2 * node + 2, pos, occupied);
        }
        
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    bool queryHasEmpty(int node, int l, int r) {
        if (tree[node].left > r || tree[node].right < l) {
            return false;
        }
        
        if (l <= tree[node].left && tree[node].right <= r) {
            return tree[node].max_empty > 0;
        }
        
        return queryHasEmpty(2 * node + 1, l, r) || 
               queryHasEmpty(2 * node + 2, l, r);
    }

    SegmentTreeNode queryMaxEmpty(int node, int l, int r) {
        if (tree[node].left >= l && tree[node].right <= r) {
            return tree[node];
        }
        
        int mid = (tree[node].left + tree[node].right) / 2;
        if (r <= mid) {
            return queryMaxEmpty(2 * node + 1, l, r);
        } else if (l > mid) {
            return queryMaxEmpty(2 * node + 2, l, r);
        } else {
            SegmentTreeNode left = queryMaxEmpty(2 * node + 1, l, mid);
            SegmentTreeNode right = queryMaxEmpty(2 * node + 2, mid + 1, r);
            return merge(left, right);
        }
    }

public:
    ParkingLot(int size) : n(size) {
        slots.resize(n, false);
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    bool hasEmpty(int l, int r) {
        if (l < 0 || r >= n || l > r) return false;
        return queryHasEmpty(0, l, r);
    }

    int maxContinuousEmpty(int l, int r) {
        if (l < 0 || r >= n || l > r) return 0;
        return queryMaxEmpty(0, l, r).max_empty;
    }

    bool parkAt(int pos) {
        if (pos < 0 || pos >= n || slots[pos]) {
            return false;
        }
        slots[pos] = true;
        update(0, pos, true);
        return true;
    }

    bool leaveAt(int pos) {
        if (pos < 0 || pos >= n || !slots[pos]) {
            return false;
        }
        slots[pos] = false;
        update(0, pos, false);
        return true;
    }
};

int main() {
    ParkingLot lot(100); 
    cout << "initial status:" << endl;
    cout << "1-5?: " << lot.hasEmpty(1, 5) << endl;
    cout << "1-5 longest: " << lot.maxContinuousEmpty(1, 5) << endl;

    cout << "\n park on tow:" << endl;
    lot.parkAt(2);
    cout << "1-5?: " << lot.hasEmpty(1, 5) << endl;
    cout << "1-5longest: " << lot.maxContinuousEmpty(1, 5) << endl;

    cout << "\n park on 3,4:" << endl;
    lot.parkAt(3);
    lot.parkAt(4);
    cout << "1-5longest?: " << lot.maxContinuousEmpty(1, 5) << endl;

    cout << "\n 2 free:" << endl;
    lot.leaveAt(2);
    cout << "1-5?: " << lot.maxContinuousEmpty(1, 5) << endl;
    system("pause");

    return 0;
}
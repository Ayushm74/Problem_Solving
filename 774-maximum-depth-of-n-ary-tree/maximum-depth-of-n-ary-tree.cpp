class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<Node*> q;
        q.push(root);

        int depth = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                for (Node* child : curr->children) {
                    q.push(child);
                }
            }

            depth++;
        }

        return depth;
    }
};
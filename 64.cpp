#include <bits/stdc++.h>
using namespace std;

class ComponentNode
{
public:
    int value;
    vector<ComponentNode *> components;
    ComponentNode(int p)
    {
        this->value = p;
    }
};

ComponentNode *ans = NULL;
float val = -1;

int solve(ComponentNode *root, int &n)
{
    if (root == NULL)
    {
        return 0;
    }
    int v = root->value;
    n = 1;
    for (auto it : root->components)
    {
        int number = 0;
        v += solve(it, number);
        n += number;
    }

    if (n == 1)
        return v;

    float w = v / n;
    if (w > val)
    {
        val = w;
        ans = root;
    }
    return v;
}

ComponentNode *getFastestComponent(ComponentNode *rootComponent)
{
    int n = 0;
    int w = solve(rootComponent, n);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ComponentNode *root = new ComponentNode(200);
    ComponentNode *root2 = new ComponentNode(120);
    ComponentNode *root3 = new ComponentNode(180);
    root->components.push_back(root2);
    root->components.push_back(root3);
    root2->components.push_back(new ComponentNode(110));
    root2->components.push_back(new ComponentNode(20));
    root2->components.push_back(new ComponentNode(30));
    root3->components.push_back(new ComponentNode(150));
    root3->components.push_back(new ComponentNode(80));

    cout << getFastestComponent(root)->value << endl;
    return 0;
}
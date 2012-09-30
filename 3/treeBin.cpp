#include "treeBin.h"
#include <iostream>

TreeBin* TreeBin::insert(int val)
{
        if (!this->value)
        {
                value = val;
                return this;
        }
        if (this->value == val)
                return this;
        else if (this->value > val)
        {
                if (left)
                        return left->insert(val);
                else
                        return (left = new TreeBin(val));
        }
        else
        {
                if (right)
                        return right->insert(val);
                else
                        return (right = new TreeBin(val));
        }
}
TreeBin* TreeBin::deleteVal(int val)
{
        if (find(val))
        {
                TreeBin *tmp = this;
                deleteHelp(tmp, val);
                return tmp;
        }
        else
                return this;
}
void TreeBin::deleteHelp(TreeBin*& t, int val)
{
        if (t->value > val)
                deleteHelp(t->left, val);
        else if(t->value < val)
                deleteHelp(t->right, val);
        else
        {
                if (!t->left && !t->right)
                        {
                                delete t;
                                t = NULL;
                        }
                else if (!t->left)
                {
                        TreeBin* tmp = t->right;
                        t->right = NULL;
                        delete t;
                        t = tmp;
                }
                else if (!t->right)
                {
                        TreeBin* tmp = t->left;
                        t->left = NULL;
                        delete t;
                        t = tmp;
                }
                else
                        t->value = deleteMinTree(t->right);

        }
}


int TreeBin::deleteMinTree(TreeBin* & t)
{
        if (t->left)
                return deleteMinTree(t->left);
        else
        {
                int k = t->value;
                delete t;
                t = NULL;
                return k;
        }
}
bool TreeBin::find(int val)
{

        if (value == val)
                return true;

        if (value > val && left)
                return left->find(val);
        if (right)
                return right->find(val);

        return false;
}

int TreeBin::iterator::next()
{
    if (!mPointer)
    {
        throw std::logic_error("not enough tree");
    }
    mPointer = stack.top();
    stack.pop();
    if (mPointer->left)
        stack.push(mPointer->left);
    if (mPointer->right)
        stack.push(mPointer->right);
    return mPointer->value;
}


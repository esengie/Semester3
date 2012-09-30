#pragma once
#include <stack>
#include <stdexcept>
class TreeBin
{
public:
        TreeBin() : left(0), right(0), value(0) {}
        ~TreeBin()
        {
                delete left;
                delete right;
        }
        TreeBin(int val): left(0), right(0), value(val) {}
        bool find(int val);
        TreeBin* insert(int val);
        TreeBin* deleteVal(int val);
        class iterator
        {
        public:
            iterator(TreeBin* blah): mPointer(blah)
            {
                stack.push(mPointer);
            }
            iterator(iterator& k): mPointer(k.mPointer){}
            int next();


        private:
            TreeBin* mPointer;
            std::stack<TreeBin*> stack;
        };
private:
        TreeBin *left;
        TreeBin *right;
        int value;
        int deleteMinTree(TreeBin*& t);
        void deleteHelp(TreeBin*& t, int val);

};

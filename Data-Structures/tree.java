import java.util.*;
import java.io.*;

class Tree
{
    int data;
    Tree left,right;


    Tree(int data){
        this.data=data;
        left=right=null;
    }

    public void insert(int data)
    {
        this.data=data;
        this.left=null;
        this.right=null;
    }

    public void inOrder(Tree node)
    {
        if(node==null)
            return;
        inOrder(node.left);
        System.out.println(node.data);
        inOrder(node.right);
    }
}
class Test
{
    public static void main(String args[])
    {
        Tree node=new Tree(7);
        node.insert(5);
        node.left.insert(3);
        node.right.insert(6);
        node.inOrder(node);
    }
    
}
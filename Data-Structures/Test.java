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


}
class Test
{
    public static void inOrder(Tree node)
    {
        if(node==null)
            return;
        inOrder(node.left);
        System.out.println(node.data);
        inOrder(node.right);
    }

    public static void main(String args[])
    {
        Tree node=new Tree(7);
        node.left=new Tree(5);
        node.right=new Tree(4);
        inOrder(node);
    }
    
}
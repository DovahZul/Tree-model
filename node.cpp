#include "node.h"
#include <stdio.h>
#include <iostream>
//#include "NodeTypes.h"

using namespace std;

    Type Node::getType()
    {
    	return t;
    }

    Node* Node::getParent()
    {
        return parent;
    }

    void Node::setParent(Node* p)
    {
    	parent = p;
    }

    Node* Node::getRight()
    {
    	if(right)
        	return right;
    }

    Node* Node::getLeft()
    {
    	if(left)
        	return left;
    }

    bool Node::canAddChild()
    {
    	if(left && right) return false;
    	return true;
    }

    void Node::addChild(Node* child)
    {
    	if(canAddChild())
    		if(!left)
    			left = child;
    		else
    			right = child;

    }
    int Node::getChildrenCount()
    {
    	if(right && left) 
    		return 2;
    		else if(!right && !left)
    		return 0;
    	return 1;

    }

   UserData* Node::getUserData()
   {
    return (UserData*) addr;
   }

   Shape* Node::getShape()
   {
    return (Shape*) addr;
   }

   AdvancedUserData* Node::getAdvancedUserData()
   {
    return (AdvancedUserData*) addr;
   }

   void Node::setUserData(UserData* val)
   {
    delete (UserData*) addr;
    addr = (long) val; 
   }

   void Node::setShape(Shape* val)
   {
    delete (Shape*) addr;
    addr = (long) val;
   }

   void Node::setAdvancedUserData(AdvancedUserData* val)
   {
    delete (AdvancedUserData*) addr;
    addr = (long) val;
   }

   int Node::getTotalChildrenCount()
   {
    int count=0;
    if(getChildrenCount() = =0) return count;
    count += getChildrenCount();
    count += right->getChildrenCount();
    count += left->getChildrenCount();

    return count;
   }

   int Node::distanceToRoot()
   {
      int dst=0;
 
        if(getParent()==0) 
          return dst;
        else
        {
          dst++;
          dst+=getParent()->distanceToRoot();  
        }    
      return dst;

    }   
    Node* Node::getRoot()
    {
      Node* walker=this;
      if(getParent())
      {
        if(getParent()->getRoot()==0)
          return getParent();
        walker=getParent()->getRoot();
      }
      return walker;
    }




    Node::Node(Type type, Node* p=0)
    {
        left=0;
        right=0;
        parent=p;
        t=type;
    }

  // // Node(addr=0,t=UserData,parent=0,left=0,right=0)
   // {
       // name=n;
       // surname=s
       // id=val;
      //  left=0;
      //  right=0;
       // parent=0;
  //  }

  //  Node::~Node(){
        //std::cout<<"Node deleted";

    //}



//
//  BinaryNode.h
//  Prac08
//
//  Created by Jurvis Tan on 10/12/15.
//  Copyright © 2015 Undertide LLP. All rights reserved.
//

#ifndef BinaryNode_h
#define BinaryNode_h

typedef int ItemType;

struct BinaryNode
{
    ItemType   item;	// data item
    BinaryNode *left;	// pointer pointing to left subtree
    BinaryNode *right;	// pointer pointing to right subtree
};

#endif /* BinaryNode_h */

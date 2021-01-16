#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
    return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
    boxes.push(b1);
    return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
    return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
    return this->boxes;
}

unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    vector<Object>::iterator it = objs.begin();
    while(it != objs.end()) {
        if( (*it).getWeight() <= boxCapacity ) {
            objects.push(*it);
            it = objs.erase(it);
        }
        else it++;
    }
    return objects.size();
}

Box PackagingMachine::searchBox(Object& obj) {
    vector<Box> temp;
    while(!boxes.empty()){
        Box bx = boxes.top();
        boxes.pop();
        if(bx.getFree() >= obj.getWeight()){
            for(int i = 0; i < temp.size(); i++)
                boxes.push(temp[i]);
            return bx;
        } else temp.push_back(bx);
    }
    for(int i = 0; i < temp.size(); i++)
        boxes.push(temp[i]);

    return Box(boxCapacity);
}

unsigned PackagingMachine::packObjects() {
    while(!objects.empty()){
        Object obj = objects.top();
        objects.pop();
        Box bx = searchBox(obj);
        bx.addObject(obj);
        boxes.push(bx);
    }
	return boxes.size();
}

string PackagingMachine::printObjectsNotPacked() const {
    stringstream ss;
    if(!objects.empty()){
        HeapObj buffer = objects;
        while(!buffer.empty()){
            Object obj = buffer.top();
            buffer.pop();
            ss << obj << endl;
        }
        return ss.str();
    }
	return "No objects!\n";
}

Box PackagingMachine::boxWithMoreObjects() const {
    if(boxes.empty()) throw MachineWithoutBoxes();
    HeapBox buffer = boxes;
    Box b = buffer.top();
    buffer.pop();
    while(!buffer.empty()){
        if(b.getSize() < buffer.top().getSize()) b = buffer.top();
        buffer.pop();
    }
	return b;
}
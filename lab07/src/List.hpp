#ifndef LIST_HPP
#define LIST_HPP
//adding this for grade
class List {
public:
    /* Returns the index in the array where value is found.
     * Return -1 if value is not present in the array.
     */
    virtual int indexOf(const int value) = 0;

    /* Removes an item at position index by shifting later elements left.
     * Returns true iff 0 <= index < size.
     */
    virtual bool remove(const int index) = 0;

    /* Insert the integer val at position pos */
    virtual void insert(const int pos, const int val) = 0;

    /* Retrieves the element at position pos */
    virtual int get(const int pos) const = 0;

    /* Sets the element at position pos to the value val.*/
    virtual int set(const int pos, const int val) = 0;

    /* Returns if the two lists contain the same elements in the
     * same order.
     */
    virtual bool equals(const List &list) = 0;

    virtual int getLength() const = 0; 	
};

#endif

#pragma once
#include <iostream>

template<typename T>
class List //List
{
public:

    template<typename T>
    List();
    List()
    {
        Size = 0;
        head = nullptr;
    }


    ~List()
    {
        //std::cout << "Deleting list..."<<std::endl;
        clear();
    }


    template<typename T>
    void behind(T dat); // додавання елементу в початок списку;
    void behind(T dat)
    {
        if (head == nullptr)
        {
            head = new Node<T>(dat);
        }
        else
        {
            Node<T>* current = new Node<T>(dat);

            current->pnext = this->head;
            this->head = current;
        }

        Size++;
    }

    template<typename T>
    void pushfront_index(int index, T dat, int not_incrise = 1); // вставлення елементу після n-го елементу списку;
    void pushfront_index(int index, T dat, int not_incrise = 1)
    {
        if (size_check(index))
        {
            int counter = 0;
            Node<T>* current = this->head;

            Node<T>* temp = nullptr;

            while (current != nullptr)
            {
                if (counter == index)
                {
                    if (current->pnext != nullptr) { temp = current->pnext; }
                    current->pnext = new Node<T>(dat, temp);
                }

                current = current->pnext;
                counter++;
            }
            if (not_incrise)
            {
                Size++;
            }

        }
        else {
            throw "Index is not identificated";
        }

    }

    template<typename T>
    void movement(int from, int to);
    void movement(int from, int to) // пересування елемента на n позицій;
    {

        if (size_check(from))
        {
            int counter = 0;
            Node<T>* current = this->head;


            Node<T>* early_element = nullptr;
            T from_data;
            if (from == 0)
            {
                from_data = head->data;

                current = current->pnext;
                this->head = current;

            }
            else
            {
                while (current != nullptr)
                {
                    if (from != 0 && counter == from - 1) // (counter == from - 1)
                    {
                        early_element = current;
                    }


                    if (from != 0 && counter == from) // (counter == from)
                    {
                        from_data = current->data;
                        early_element->pnext = current->pnext;
                        break;
                    }

                    current = current->pnext;
                    counter++;
                }
            }

            pushfront_index(to - 1, from_data, 0);
        }
        else {
            throw "#____Index is not identificated____#";
        }
    }

    template<typename T>
    void pushback(T dat);
    void pushback(T dat) // додавання елементу в кінець списку;
    {

        if (head == nullptr)
        {
            head = new Node<T>(dat);
        }
        else
        {
            Node<T>* current = this->head;

            while (current->pnext != nullptr)
            {
                current = current->pnext;
            }

            current->pnext = new Node<T>(dat);


        }
        Size++;
    }

    template<typename T>
    T& operator[](const int index);
    T& operator[](const int index)
    {
        int counter = 0;
        Node<T>* current = this->head;

        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }

            current = current->pnext;
            counter++;
        }
    }

    template<typename T>
    void remove_element(int index);
    void remove_element(int index) // видалення за індексом
    {
        if (!size_check(index))
        {
            throw "Index is not identificated";
        }
        if (index == 0)
        {
            Node<T>* current = this->head;
            head = current->pnext;

            delete current;

            this->Size = Size - 1;
        }
        else
        {
            int counter = 0;
            Node<T>* current = this->head;
            Node<T>* early_element = nullptr;

            while (current->pnext != nullptr)
            {
                if (counter == index - 1) { early_element = current; }

                if (counter == index)
                {
                    early_element->pnext = current->pnext;
                    break;
                }
                current = current->pnext;
                ++counter;
            }
            delete current;

            this->Size = Size - 1; // Size--; ERROR
        }
    }

    template<typename T>
    void sort_list();
    void sort_list()
    {
        T temp;

        for (int i = 0; i < Size - 1; ++i)
        {
            for (int j = 0; j < Size - i - 1; ++j)
            {
                if (at(j) > at(j + 1))
                {

                    temp = at(j);
                    at(j) = at(j + 1);
                    at(j + 1) = temp;
                }
            }

        }
    }

    template<typename T>
    int GetSize();
    int GetSize()
    {
        return Size;
    }

    template<typename T>
    void copy_to(List<T>& n); // копіювання цього листа до іншого
    void copy_to(List<T>& n)
    {
        Node<T>* current = this->head;
        while (current != nullptr)
        {
            n.pushback(current->data);
            current = current->pnext;
        }
    }

    template<typename T>
    void gluing_to(List<T>& l2); // склеювання цього лист з іншим
    void gluing_to(List<T>& l2)
    {

        Node<T>* current = head->pnext;
        while (current->pnext != nullptr)
        {
            current = current->pnext;
        }
        current->pnext = l2.head;
    }

    template<typename T>
    List<T> both_listing(List<T>& l2); // створення окремого масиву, який має спільні елементи обох масиву.
    List<T> both_listing(List<T>& l2)
    {
        if (l2.Size != 0 && this->Size != 0)
        {
            List<T> new_list;
            Node<T>* current = this->head;

            for (int i = 0; i < l2.GetSize(); ++i)
            {
                while (current != nullptr)
                {
                    if (current->data == l2[i])
                    {
                        new_list.pushback(current->data);
                        break;
                    }
                    current = current->pnext;
                }
                current = this->head;
            }

            return new_list;
        }
        else
        {
            throw "#___One or both list hasn't any elements___#";
        }
    }

    template<typename T>
    void pop_front();
    void pop_front() // видалення з початку списку
    {
        Node<T>* temp = this->head;
        head = head->pnext;

        delete temp;

        this->Size -= 1; // Size--; ERROR
    }

    template<typename T>
    void show_list();
    void show_list()
    {
        Node<T>* current = head;
        int i = 0;
        while (current != nullptr)
        {
            std::cout << i << ". " << current->data << std::endl;
            ++i;
            current = current->pnext;
        }
    }

private:
    template<typename T>
    struct Node
    {
        Node* pnext;
        T data;
        Node(T m, Node<T>* pNext = nullptr)
        {
            this->data = m;
            this->pnext = pNext;
        }

    };

    template<typename T>
    void clear();
    void clear() // очищення списку
    {
        while (Size)
        {
            pop_front();
        }
    }




    template<typename T>
    bool size_check(int index);
    bool size_check(int index)
    {
        if (0 <= index && index < Size) {
            return true;
        }
        else
        {
            return false;
        }
    }

    template<typename T>
    T& at(int index);
    T& at(int index)
    {
        if (size_check(index))
        {
            Node<T>* current = this->head;
            int counter = 0;

            while (current != nullptr)
            {
                if (counter == index)
                {
                    return current->data;
                }
                current = current->pnext;
                ++counter;
            }
        }
        else {
            throw "Index is not identificated";
        }
    }

    int Size;

    Node<T>* head;
};



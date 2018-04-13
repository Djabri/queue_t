
#include <iostream>
template <typename T>
class queue_t {
private:
	struct node_t {
		node_t *next;
		T value;
	};
private:
	using link = node_t * ;
	link head;
	link tail;
public:
	queue_t() : head(nullptr), tail(nullptr) noexcept
	{

	}

	queue_t(queue_t & other) {
		for (link t = other.head; t != nullptr; t = t->next) {
			push(t->value);
		}
	}

	void push(T value) {
		if (head == nullptr) {
			head = new node_t;

			head->value = value;
			head->next = nullptr;

			tail = head;
		}

		tail->next = new node_t;
		tail->next->value = value;

		tail->next->next = nullptr;
		tail = tail->next;
	}
	T pop() {
		if (head == nullptr) {
			throw "Erorr!\n Queue is empty, try again";
		}

		T result = head->value;
		link head_ = head->next;

		if (head == tail) {
			head_ = nullptr;
			tail = nullptr;
		}

		delete head;
		head = head_;
		return result;
	}
	void show_elements() {
		for (link t = head; t != nullptr; t = t->next) {
			std::cout << t->value;
		}
	}
	~queue_t() {
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (head != nullptr) {
			pop();
		}

		head = nullptr;
		tail = nullptr;
		return;
	}
};

"""
* Ori Angel
* 314617739
* 01
* ass07
"""
import sys

# const variables
EMPTY = ""
SPACE = " "
END_LINE = "\n"
COMMA_DOT = ";"
COMMA = ","
TWO_POINTS = ":"
AND = "&"
OR = "|"
SYMMETRICAL = "^"


def main():
    # build the dictionary with all the data
    dictionary = build_dictionary()
    # build the questions DB
    questions = dict()
    # print the menu
    print_menu(dictionary, questions)


"""
*The space between the comments and the functions is part of auto style of PyCharm.
* Function Name: print_menu
* Input:   dictionary with the date that was taken from the text file and question that
           include the database of questions that already ask
* Output:  -
* Function Operation: print the menu and call to the specific functions
"""


def print_menu(dictionary, questions):
    print('''Please select an operation:
\t0. Exit.
\t1. Query by category.
\t2. Query by item.
\t3. Purchase an item.
\t4. Admin panel.''')
    fun = input()
    if fun == '0':
        exit()
    elif fun == '1':
        query_by_category(dictionary, questions)
    elif fun == '2':
        query_by_item(dictionary, questions)
    elif fun == '3':
        purchase_an_item(dictionary, questions)
    elif fun == '4':
        admin_pass(dictionary, questions)
    else:
        print("Error: unrecognized operation.")
    print_menu(dictionary, questions)


"""
* Function Name: build_dictionary
* Input: -
* Output: dictionary with the date in the text file
* Function Operation: scan text file and insert the data to dictionary
"""


def build_dictionary():
    store = sys.argv[1]
    file = open(store, 'r')
    dictionary = dict()
    for line in file:
        # clean \n and last \n
        if line == END_LINE:
            continue
        if line.endswith(END_LINE):
            category_line = line[:-2]
        else:
            category_line = line[:-1]
        category_arr = category_line.split(TWO_POINTS)
        category_name = category_arr[0]
        category_name = category_name.lstrip(SPACE)
        # build the items dictionary for every category
        items = dict()
        if len(category_arr) >= 2:
            category_items = category_arr[1]
            category_items = category_items.lstrip(SPACE)
            products_arr = category_items.split(COMMA_DOT)
            for i in products_arr:
                name, price = i.split(COMMA)
                items[name.lstrip(SPACE)] = price.lstrip(SPACE)
        dictionary[category_name] = items
    file.close()
    return dictionary


"""
* Function Name: key_in_dict
* Input: dictionary, key
* Output: return true if key in dictionary and false if not
* Function Operation: return true if key in dictionary and false if not
"""


def key_in_dict(dictionary, key):
    if key in dictionary:
        return True
    return False


"""
* Function Name: check_compare_input
* Input: dictionary, string
* Output: return false if the string is not correct 
* Function Operation: check if the string correct
"""


def check_compare_input(dictionary, string):
    if len(string) < 3:
        print("Error: not enough data.")
        return False

    if not key_in_dict(dictionary, string[0]) or not key_in_dict(dictionary, string[1]):
        print("Error: one of the categories does not exist.")
        return False
    if string[2] != '&' and string[2] != '|' and string[2] != '^' or len(string) > 3:
        print("Error: unsupported query operation.")
        return False
    return True


"""
* Function Name: operator_function
* Input: dictionary, questions with the DB for cached categories and operator
* Output: -
* Function Operation: do the input operator between 2 categories 
"""


def operator_function(dictionary, questions, string, operator):
    q1 = questions_database(questions, string[0] + string[1] + operator)
    q2 = questions_database(questions, string[1] + string[0] + operator)
    if q1 is not None:
        print("Cached: %s" % q1)
        return
    if q2 is not None:
        print("Cached: %s" % q2)

    else:
        answer = EMPTY
        if operator == AND:
            answer = dictionary[string[0]].keys() & dictionary[string[1]].keys()
        if operator == OR:
            answer = dictionary[string[0]].keys() | dictionary[string[1]].keys()
        if operator == SYMMETRICAL:
            answer = dictionary[string[0]].keys() ^ dictionary[string[1]].keys()
        answer = sorted(answer)
        # insert question to DB
        questions.update({string[0] + string[1] + operator: answer})
        print(answer)


"""
* Function Name: query_by_category
* Input: dictionary questions with the DB for cached
* Output: -
* Function Operation: scan string with categories and operator and call to operator function
"""


def query_by_category(dictionary, questions):
    string = input()
    string = [x.lstrip() for x in string.split(',')]
    if check_compare_input(dictionary, string):
        if string[2] == AND:
            operator_function(dictionary, questions, string, AND)
        if string[2] == OR:
            operator_function(dictionary, questions, string, OR)
        if string[2] == SYMMETRICAL:
            operator_function(dictionary, questions, string, SYMMETRICAL)


"""
* Function Name: value_in_dict
* Input: dictionary and item
* Output: true if the item in dictionary
* Function Operation: check if item in dictionary
"""


def value_in_dict(dictionary, item):
    for i in dictionary.keys():
        for key in dictionary[i]:
            if key == item:
                return True
    return False


"""
* Function Name: check_db
* Input: questions with DB and question
* Output: true if the question in the DB
* Function Operation: check if question in DB
"""


def check_db(questions, question):
    question = questions_database(questions, question)
    if question is not None:
        print("Cached: %s" % question)
        return True

    return False


"""
* Function Name: query_by_item
* Input: dictionary and questions with DB
* Output: -
* Function Operation: main function for query item - print the relate items
"""


def query_by_item(dictionary, questions):
    # check if the input is correct
    item = input_item(dictionary)
    if item is not None:
        # check if the question in DB
        if not check_db(questions, item):
            list_relate_items = []
            for i in dictionary.keys():
                if key_in_dict(dictionary[i].keys(), item):
                    for key in dictionary[i]:
                        # check not to print same item
                        if not key == item and item not in list_relate_items:
                            list_relate_items.append(key)

            list_relate_items = sorted(list_relate_items)
            questions.update({item: list_relate_items})
            print(list_relate_items)


"""
* Function Name: input_item
* Input: dictionary 
* Output:  item after after checking 
* Function Operation: scan item and check if the scan correct
"""


def input_item(dictionary):
    item = input()
    item = item.lstrip(SPACE)
    if not value_in_dict(dictionary, item):
        print("Error: no such item exists.")
        return None
    return item


"""
* Function Name: find_price
* Input: dictionary and item
* Output:  -
* Function Operation: scan item and find his price
"""


def find_price(dictionary, item):
    for i in dictionary.keys():
        for key in dictionary[i]:
            if key == item:
                print('You bought a brand new "%s" for %s$.' % (item, dictionary[i].get(item)))
                return


"""
* Function Name: remove_item
* Input: dictionary and item
* Output:  -
* Function Operation: remove item from dictionary
"""


def remove_item(dictionary, item):
    for i in dictionary.keys():
        for key in dictionary[i]:
            if key == item:
                del dictionary[i][item]
                return True
    return False


"""
* Function Name: purchase_an_item
* Input: dictionary and questions with db to update
* Output:  -
* Function Operation: main function for purchase and item
"""


def purchase_an_item(dictionary, questions):
    item = input_item(dictionary)
    if item is not None:
        # find the price and print him
        find_price(dictionary, item)
        # remove the item after buying
        is_remove = True
        while is_remove:
            is_remove = remove_item(dictionary, item)
        questions.clear()


"""
* Function Name: admin_pass
* Input: dictionary and questions with DB
* Output:  -
* Function Operation: check if the password that was scan is correct
"""


def admin_pass(dictionary, questions):
    password = input("Password: ")
    password = password.lstrip(SPACE)
    admin = sys.argv[2]
    file = open(admin, 'r')
    text_p = EMPTY
    for line in file:
        text_p = line

    file.close()
    if text_p == password:
        admin_menu(dictionary, questions)
    else:
        print("Error: incorrect password, returning to main menu.")


"""
* Function Name: category_in_dict
* Input: dictionary, category_names
* Output:  true if the category is in dictionary
* Function Operation: check if the category is in dictionary
"""


def category_in_dict(dictionary, category_names):
    for i in category_names:
        if i not in dictionary.keys():
            print("Error: one of the categories does not exist.")
            return False
    return True


"""
* Function Name: check_price
* Input: price
* Output:  true if price is correct (int)
* Function Operation: check if price is correct (int)
"""


def check_price(price):
    try:
        int(price)
        return True
    except ValueError:
        print("Error: price is not a positive integer.")
        return False


"""
* Function Name: insert_update_fun
* Input: dictionary, category_names, item_name, item_price
* Output:  -
* Function Operation: insert new item to dictionary
"""


def insert_update_fun(dictionary, category_names, item_name, item_price):
    for i in category_names:
        if item_name in dictionary[i]:
            dictionary[i][item_name] = item_price
        else:
            dictionary[i].update({item_name: item_price})


"""
* Function Name: save_file
* Input: file_name, dictionary
* Output:  -
* Function Operation: save the dictionary to special file
"""


def save_file(file_name, dictionary):
    file = open(file_name, 'w')
    list_category = []
    for i in dictionary.keys():
        list_category.append(i)
    list_category.sort()
    for items in list_category:
        if dictionary[items] == {}:
            category = str(items) + ":"
        else:
            category = str(items) + ": " + str(sorted(dictionary[items]))
        if items != list_category[-1]:
            file.write(category + END_LINE)
        else:
            file.write(category)
    file.close()
    print('Store saved to "out.txt".')


"""
* Function Name: insert_or_update_item
* Input:  dictionary, questions
* Output:  -
* Function Operation: add or update the item to dictionary
"""


def insert_or_update_item(dictionary, questions):
    new_item = input()
    category_arr = new_item.split(TWO_POINTS)
    category_names = category_arr[0]
    category_names = [x.lstrip() for x in category_names.split(COMMA)]
    if category_names == EMPTY:
        print("Error: not enough data.")
        return
    if not category_in_dict(dictionary, category_names):
        return
    new_item = category_arr[1]
    new_item = [x.lstrip() for x in new_item.split(COMMA)]
    item_name = new_item[0]
    item_price = new_item[1]
    if item_name == EMPTY or item_price == EMPTY:
        print("Error: not enough data.")
        return
    if not check_price(item_price):
        return
    insert_update_fun(dictionary, category_names, item_name, item_price)
    questions.clear()
    print('Item "%s" added.' % item_name)


"""
* Function Name: admin_menu
* Input:  dictionary, questions
* Output:  -
* Function Operation: print admin menu
"""


def admin_menu(dictionary, questions):
    print('''Admin panel:
\t0. Return to main menu.
\t1. Insert or update an item.
\t2. Save.''')
    fun = input()
    if fun == '0':
        print_menu(dictionary, questions)
    elif fun == '1':
        insert_or_update_item(dictionary, questions)
    elif fun == '2':
        out = sys.argv[3]
        save_file(out, dictionary)
    else:
        print("Error: unrecognized operation.")
    admin_menu(dictionary, questions)


"""
* Function Name: questions_database
* Input:  questions, new_question
* Output:  return the answer for questions that in DB
* Function Operation:return the answer for questions that in DB
"""


def questions_database(questions, new_question):
    for q in questions.keys():
        if new_question == q:
            return questions[q]  # return answer
    return None


if __name__ == "__main__":
    main()

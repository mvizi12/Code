import HW_4_Student_Class #Imports the "Student" class that was created in another module
import matplotlib.pyplot as plt #Imports the functions necessary to display a bar chart

def make_list(): #Creates instances of the "Student" class & adds them to a list
    student_list = list()
    print("Enter your info")
    for i in range(1, 13): #Asks the user for 12 students' info
        name = input("Enter your name: ")
        age = int(input("Enter your age: "))
        print("Action, Sci-Fi, Comedy, History")
        movie_genre = input("Enter 'Like' or 'Dislike' for the aforementioned genres seperated by spaces\n")
        movie_genre = movie_genre.strip('.,!\n ').split()
        movie_genre2 = list()
        print()
        for word in movie_genre:
            word=word.strip(",.;:' ")
            word=word.upper()
            movie_genre2.append(word)
        student = HW_4_Student_Class.Student(name, age, movie_genre2) #Creates an instance of the "Student" class
        student_list.append(student) #Adds the instance to a list
    print("Name of Student", "\t", "Age", "\t", "Movie Genre[Action, Sci-Fi, Comedy, History]")
    for item in student_list: #Displays each students' info
        print(item.get_name(), "\t", item.get_age(), "\t", item.get_movie_genre())
    print()
    return student_list #Assigns the created list of instances to the "make_list" function

#Function that finds the favorite genre of all the students in the specified age group
def find_fav_genre(age_group, students):
    stud_age_group = list()
    for student in students: #Adds each student to a list if they meet the criteria for the specified group
        if age_group == 'E':
            if 5<=student.get_age()<=9:
                stud_age_group.append(student)
        elif age_group == 'M':
            if 10<=student.get_age()<=14:
                stud_age_group.append(student)
        elif age_group == 'H':
            if 15<=student.get_age()<=18:
                stud_age_group.append(student)
        else:
            if 19<=student.get_age()<=22:
                stud_age_group.append(student)
    action = 0
    sci_fi = 0
    comedy = 0
    history = 0
    for student in stud_age_group: #Increases the counter for the number of students that like each genre
        if student.get_movie_genre()[0] == 'LIKE':
            action += 1
        if student.get_movie_genre()[1] == 'LIKE':
            sci_fi += 1
        if student.get_movie_genre()[2] == 'LIKE':
            comedy += 1
        if student.get_movie_genre()[3] == 'LIKE':
            history += 1

    print("Age Group: ", age_group)
    print("Favorite Movie Genre:", end="")
    if action == 0 and sci_fi == 0 and comedy == 0 and history == 0:
        print("Nobody likes anything")
    elif action == sci_fi == comedy == history:
        print("Action, Sci-Fi, Comedy, History")
    else:
        genre_dict = {'Action': action, 'Sci-Fi': sci_fi, 'Comedy': comedy, 'History': history}
        fav_genre = max(action, sci_fi, comedy, history)
        for k, v in genre_dict.items():
            if fav_genre == v:
                print(k, " ", end="")
    print("\n")

#Function that finds the percentage of all the students that like each genre in the specified age group
def calc_percentage_genre(age_group, students):
    stud_age_group = list()
    for student in students: #Adds each student to a list if they meet the criteria for the specified group
        if age_group == 'E':
            if 5<=student.get_age()<=9:
                stud_age_group.append(student)
        elif age_group == 'M':
            if 10<=student.get_age()<=14:
                stud_age_group.append(student)
        elif age_group == 'H':
            if 15<=student.get_age()<=18:
                stud_age_group.append(student)
        else:
            if 19<=student.get_age()<=22:
                stud_age_group.append(student)

    action = 0
    sci_fi = 0
    comedy = 0
    history = 0
    
    for student in stud_age_group: #Increases the counter for the number of students that like each genre
        if student.get_movie_genre()[0] == 'LIKE':
            action += 1
        if student.get_movie_genre()[1] == 'LIKE':
            sci_fi += 1
        if student.get_movie_genre()[2] == 'LIKE':
            comedy += 1
        if student.get_movie_genre()[3] == 'LIKE':
            history += 1

    total = len(stud_age_group)
    print("Age Group:", age_group)
    if total == 0: #Prevents the program from diving by 0
        print("There are no students in this age group")
    else: #Displays the percentage for each genre
        print("% of students who like Action:", float((action/total))*100)
        print("% of students who like Sci-Fi:", float((sci_fi/total))*100)
        print("% of students who like Comedy:", float((comedy/total))*100)
        print("% of students who like History:", float((history/total))*100)
    print()

#Function to create & display a bar graph based on the percentages found in the previous function
def bar_graph(age_group, students):
    stud_age_group = list()
    for student in students:
        if age_group == 'E':
            if 5<=student.get_age()<=9:
                stud_age_group.append(student)
        elif age_group == 'M':
            if 10<=student.get_age()<=14:
                stud_age_group.append(student)
        elif age_group == 'H':
            if 15<=student.get_age()<=18:
                stud_age_group.append(student)
        else:
            if 19<=student.get_age()<=22:
                stud_age_group.append(student)

    action = 0
    sci_fi = 0
    comedy = 0
    history = 0
    
    for student in stud_age_group:
        if student.get_movie_genre()[0] == 'LIKE':
            action += 1
        if student.get_movie_genre()[1] == 'LIKE':
            sci_fi += 1
        if student.get_movie_genre()[2] == 'LIKE':
            comedy += 1
        if student.get_movie_genre()[3] == 'LIKE':
            history += 1

    total = len(stud_age_group)
    if total == 0:
        print("There are no students in this age group")
    else:
        action = float((action/total) * 100)
        sci_fi = float((sci_fi/total) * 100)
        comedy = float((comedy/total) * 100)
        history = float((history/total) * 100)
        plt.bar(range(1, 5), [action, sci_fi, comedy, history], color=('r', 'b','g', 'c')) #Creates a bar chart
        plt.xticks([1, 2, 3, 4], ['Action', 'Sci-Fi', 'Comedy', 'History']) #Labels the x-tick-marks
        plt.yticks([25, 50, 75, 100], ['25%', '50%', '75%', '100%']) #Labels the y-tick-marks
        plt.ylim(ymin=0, ymax=100) #Increases the y-axis to extend to 100
        plt.xlabel('Movie Genres')
        plt.ylabel('Percentage')
        plt.title(age_group)
        plt.show()

def main():
    students = make_list()
    find_fav_genre('E', students)
    find_fav_genre('M', students)
    find_fav_genre('H', students)
    find_fav_genre('C', students)
    calc_percentage_genre('E', students)
    calc_percentage_genre('M', students)
    calc_percentage_genre('H', students)
    calc_percentage_genre('C', students)
    bar_graph('E', students)
    bar_graph('M', students)
    bar_graph('H', students)
    bar_graph('C', students)

main() #starts the entire program

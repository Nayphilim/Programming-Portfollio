import random
import pickle
import os


attributes = {}
skills = []
character = "default"
character_name = "Hero"
level = 0
turn = 1
gift_counter = 0
milestones = ["Strength10", "Strength25", "Strength50", "Constitution10", "Constitution25", "Constitution50", "Dexterity10", "Dexterity25", "Dexterity50", "Intelligence10", "Intelligence25", "Intelligence50", "Luck10", "Luck25", "Luck50" ]

#prints out tooltips to help players
def help():
    print("Hello and welcome to the roguelike progression system. This program is designed to demonstrate a",
                                "functioning progression system housed in a roguelike game.",
                                "\n"
                                "The aim of the program is to create a character which will progress and get stronger by levelling up. The level up",
                                "mechanic in this is to simulate playing through a game and gaining experience points for completing various tasks." ,
                                "Each time you choose to level up you will be given a selection of either attributes or skills that will",
                                "benefit your character. These choices will stick with your character permanently but do not fret if you",
                                "make a bad choice! You can always make a new character! ",
                                "\n",
                                "Below is information on each of the options you will be able to pick in this program",
                                "\n",
                                "New Character",
                                "\n",
                                "This option will allow you to create a character and progress through the rest of the program.",
                                "\n",
                                "Load Character",
                                "\n",
                                "If you have already made a character and saved it you can load that character with this option and",
                                "progress where you left off",
                                "\n",
                                "Help",
                                "\n",
                                "This will be available at almost all menus throughout the program. If you ever get stuck just pick that and",
                                "you will be given help specific to the part of the program you’re in. If you ever want an overview of",
                                "everything in the program visit here.",
                                "\n",
                                "Quit",
                                "\n",
                                "Stops the program and loses any progress made",
                                "\n",
                                "Save and Quit",
                                "\n",
                                "Gives you the option to save your character and then quit to the main menu",
                                "\n",
                                "Level up",
                                "\n",
                                "Simulates the character getting enough experience points (exp) to go to the next level and get stronger",
                                "\n" ,                
                                "View character",
                                "\n",                
                                "Gives an overview of your character including its name, level, attributes and skills",
                                "\n",
                                "Key terms",
                                "\n",
                                "Level",
                                "\n",
                                "This is a number given based on how many times you have surpassed the amount of experience points needed.",
                                "This is a gauge of how much you have played the game and how strong you are. In this program there",
                                "is no exp system as no gameplay is available. However, the point is that this can be easily implemented",
                                "into a full game and use experience points",
                                "\n",
                                "Attributes",
                                "\n",
                                "Attributes are the core strength of a character, this is a point-based system split into multiple categories.",
                                "Each category gives a unique bonus and the more points in that category the larger the bonus you will get.",
                                "You will get a certain amount of attribute points to spend based on their current level. When you get a certain",
                                "amount of points in an attribute you will reach an attribute milestone and get a special bonus. These points",
                                "will not affect any gameplay in this program, they are purely a demonstration of how the system works",
                                "\n",
                                "Skills",
                                "\n",
                                "Skills are game changing abilities that the character gains, for example “you can now dodge an incoming attack”.",
                                "In this program, skills will be purely a proof of concept and won’t change anything.",
                                "\n",
                                "Gift from the gods",
                                "\n",
                                "Gift’s from the gods are special bonuses granted rarely when levelling up. If you gain a gift from the gods",
                                "you will be presented 3 choices of bonuses that will strengthen your character in various ways, like picking",
                                "skills and attributes.",
                                "\n",
                                sep = "\n"
                        
                                )
    input("press enter to return to the previous menu")

#loads characters that player can load and then loads character they choose
def load():
    character_saves = os.listdir(r"character_saves/")[0:]
    counter = 1
    global character_name
    global character
    global level
    global gift_counter
    global turn
    global attributes
    global skills
    global milestones

    
    if len(character_saves) > 0:
        print("Please choose a character to load")
        for files in character_saves:
            print(str(counter ) + ". " + files)
            counter += 1
        print(str(counter) + ". Back")
        while True:
            choice = input("\n")
            if choice == "":
                print("That is not a valid input, please try again!")
                continue
            else:
                choice = int(choice)
                if choice > 0 and choice <= counter:
                    if choice == counter: # if choice is back then go to the main menu
                        main()
                    else: #if choice is valid and not back, load character
                        file = open("character_saves/" + character_saves[choice-1], "rb")
                        character_name = pickle.load(file)
                        character = pickle.load(file)
                        level = pickle.load(file)
                        gift_counter = pickle.load(file)
                        turn = pickle.load(file)
                        attributes = pickle.load(file)
                        skills = pickle.load(file)
                        milestones = pickle.load(file)
                        file.close
                        character_menu()
                else: #if choice is not valid
                    print("Thats not a valid choice, please choose another!")
                    continue
    else: #if there are no saves in the directory
        print("You dont have any saved character! Start playing the game and save your characters to access them here")
        main()
            
        
    
def set_gift(choice):
    global attributes
    global skills
    
    if choice == "Gain a 40% bonus to Strength and Constitution":
        attributes["Strength"] = round(attributes["Strength"]*1.4)
        attributes["Constitution"] = round(attributes["Constitution"]*1.4)
    elif choice == "Gain a 40% bonus to Dexterity and Luck":
        attributes["Dexterity"] = round(attributes["Dexterity"]*1.4)
        attributes["Luck"] = round(attributes["Luck"]*1.4)
    elif choice == "Gain a 40% bonus to Intelligence and Luck":
        attributes["Intelligence"] = round(attributes["Intelligence"]*1.4)
        attributes["Luck"] = round(attributes["Luck"]*1.4)
    elif choice == "Gain 10 Strength":
        attributes["Strength"] += 10
    elif choice == "Gain 10 Constitution":
        attributes["Constitution"] += 10 
    elif choice == "Gain 10 Dexterity":
        attributes["Dexterity"] += 10 
    elif choice == "Gain 10 Intelligence":
        attributes["Intelligence"] += 10 
    elif choice == "Gain 10 Luck":
        attributes["Luck"] += 10
    elif choice == "Gain 3 random skills but lose 2 you currently have at random":
        skill_list = ["extended dodge", "heavy weight", "light weight", "shorty", "sure guard", "charge", "focus", "lucky shot", "hot stuff", "ice cold", "confusion", "sprint", "thorny", "sharpshooter", "scream aim and fire", "dirty", "squeaky clean", "dazzling smile", "dark sight", "spectral", "natures call", "lash back", "money grabber"]
        counter = 0
        while counter < 2:
            rand = random.randint(0, len(skills)-1)
            print("\nyou lost the skill " + skills[rand])
            del skills[rand]
            counter += 2
        counter = 0
        while counter < 3:
            rand = random.randint(0, len(skill_list)-1)
            if skill_list[rand] not in skills:
                print("\nyou gained the skill " + skill_list[rand])
                skills.append(skill_list[rand])
                del skill_list[rand]
                counter += 1
            else:
                continue
        
        
        

def get_gifts():
    global gift_counter
    gift_counter += 1
    gift_list = ["Gain a 40% bonus to Strength and Constitution", "Gain a 40% bonus to Dexterity and Luck", "Gain a 40% bonus to Intelligence and Luck", "Gain 10 Strength", "Gain 10 Constitution", "Gain 10 Intelligence", "Gain 10 Luck", "Gain 3 random skills but lose 2 you currently have at random"]
    available_gifts = []
    counter = 0
    
    while counter < 3:
        rand = random.randint(0, len(gift_list)-1)
        available_gifts.append(gift_list[rand])
        del gift_list[rand]
        counter += 1
    return available_gifts
        
    

def check_gift():
    if gift_counter < 2:
        rand = random.randint(1, 101-level)
        if rand == 1:
            return True
        else:
            return False

#applies milestone bonus when attribute milestone is reached
def set_milestone(milestone_reached):
    global attributes
    global skills
    global milestones
    if milestone_reached == "Strength10":
        attributes["Constitution"] += 5
        attributes["Intelligence"] -= 3
        milestones.remove('Strength10')
    elif milestone_reached == "Strength25":
        skills.append("berserker")
        milestones.remove('Strength25')
    elif milestone_reached == "Strength50":
        skills.append("duel wield")
        milestones.remove('Strength50')
    elif milestone_reached == "Constitution10":
        skills.append("passive healing")
        milestones.remove('Constitution10')
    elif milestone_reached == "Constitution25":
        attributes["Constitution"] = round(attributes["Constitution"] * 1.3)
        milestones.remove('Constitution25')   
    elif milestone_reached == "Constitution50":
        skills.append("stable")
        milestones.remove('Constitution50')
    elif milestone_reached == "Dexterity10":
        attributes["Constitution"] += 2
        attributes["Luck"] += 2
        milestones.remove('Dexterity10')
    elif milestone_reached == "Dexterity25":
        skills.append("double dodge")
        milestones.remove('Dexterity25')
    elif milestone_reached == "Dexterity50":
        skills.append("multishot")
        milestones.remove('Dexterity50')
    elif milestone_reached == "Intelligence10":
        attributes["Luck"] += 10
        attributes["Dexterity"] =  round(attributes["Dexterity"]*0.6)
        attributes["Constitution"] =  round(attributes["Constitution"]*0.6)
        milestones.remove('Intelligence10')
    elif milestone_reached == "Intelligence25":
        skills.append("blast zone")
        milestones.remove('Intelligence25')
    elif milestone_reached == "Intelligence50":
        skills.append("reflect")
        milestones.remove('Intelligence50')   
    elif milestone_reached == "Luck10":
        skills.append("by a hair")
        milestones.remove('Luck10')
    elif milestone_reached == "Luck25":
        skills.append("volatile")
        milestones.remove('Luck25')
    elif milestone_reached == "Luck50":
        skills.append("now you see me")
        milestones.remove('Luck50')
    print("congratulations! You've reached a new milestone for " + milestone_reached[0:(len(milestone_reached))-2] + " by getting " + milestone_reached[-2:] + " attribute points!"  )
    
#checks for any attribute milestones reached after levelling up
def check_milestone():
    global milestones
    global attributes
    if attributes["Strength"] >= 50:
        if "Strength50" in milestones:
            set_milestone("Strength50")
    elif attributes["Strength"] >= 25:
        if "Strength25" in milestones:
            set_milestone("Strength25")
    elif attributes["Strength"] >= 10:
        if "Strength10" in milestones:
            set_milestone("Strength10")
    if attributes["Constitution"] >= 50:
        if "Constitution50" in milestones:
            set_milestone("Constitution50")
    elif attributes["Strength"] >= 25:
        if "Constitution25" in milestones:
            set_milestone("Constitution25")
    elif attributes["Constitution"] >= 10:
        if "Constitution10" in milestones:
            set_milestone("Constitution10")
    if attributes["Dexterity"] >= 50:
        if "Dexterity50" in milestones:
            set_milestone("Dexterity50")
    elif attributes["Dexterity"] >= 25:
        if "Dexterity25" in milestones:
            set_milestone("Dexterity25")
    elif attributes["Dexterity"] >= 10:
        if "Dexterity10" in milestones:
            set_milestone("Dexterity10")
    if attributes["Intelligence"] >= 50:
        if "Intelligence50" in milestones:
            set_milestone("Intelligence50")
    elif attributes["Intelligence"] >= 25:
        if "Intelligence25" in milestones:
            set_milestone("Intelligence25")
    elif attributes["Intelligence"] >= 10:
        if "Intelligence10" in milestones:
            set_milestone("Intelligence10")
    if attributes["Luck"] >= 50:
        if "Luck50" in milestones:
            set_milestone("Luck50")
    elif attributes["Luck"] >= 25:
        if "Luck25" in milestones:
            set_milestone("Luck25")
    elif attributes["Luck"] >= 10:
        if "Luck10" in milestones:
            set_milestone("Luck10")
            
        
    
#gets 3 random attributes for the player to choose
def get_attributes():
    attribute_list = ["Strength", "Constitution", "Dexterity", "Intelligence", "Luck"]
    available_attributes = []
    counter = 0
    while counter < 3:
        rand = random.randint(0, len(attribute_list)-1)
        available_attributes.append(attribute_list[rand])
        del attribute_list[rand]
        counter += 1
    return available_attributes
        
#gets 3 random skills for the player to choose
def get_skills():
    global skills
    skill_list = ["extended dodge", "heavy weight", "light weight", "shorty", "sure guard", "charge", "focus", "lucky shot", "hot stuff", "ice cold", "confusion", "sprint", "thorny", "sharpshooter", "scream aim and fire", "dirty", "squeaky clean", "dazzling smile", "dark sight", "spectral", "natures call", "lash back", "money grabber"]
    available_skills = []
    counter = 0
    while counter < 3:
        rand = random.randint(0, len(skill_list)-1)
        if skill_list[rand] not in skills:
            available_skills.append(skill_list[rand])
            del skill_list[rand]
            counter += 1
        else:
            continue
    return available_skills

#levels up the player and allows them to pick from 3 attributes/skills
def level_up():
    global level
    global attributes
    global skills
    global turn
    
    if level < 100:
        level += 1
        print("Da Ding!\nYou levelled up! Please choose one of the following:") 
        while True:
            if turn < 5: #if there has been less than 5 level cycles display attributes
                available_attributes = get_attributes()
                if level <= 10:
                    attribute_points = 3
                elif level <= 50:
                    attribute_points = 2
                else:
                    attribute_points = 1
                print("\nYou will get " + str(attribute_points) + " attribute points for the attribute you choose")   
                print("\n\n1. " + available_attributes[0],
                      "\n",
                      "2. " +  available_attributes[1],
                      "\n",
                      "3. " + available_attributes[2],
                    sep = "\n"
                        )
                while True:
                    choice = input("\n")
                    if choice == "":
                        print("that is not a valid choice, please choose again!")
                        continue
                    else:
                        choice = int(choice)
                    if choice > 0 and choice <= 3:
                        print("you have chosen to add " + str(attribute_points) + " points to " + available_attributes[choice - 1])
                        attributes[available_attributes[choice - 1]] += attribute_points  
                        break
                    else:
                        print("that is not a valid choice, please choose again")
                        continue
                turn += 1
                check_milestone()
                gift = check_gift()
                if gift is True:
                    print("...",
                          "Hm?",
                          "...",
                          "\nYou've received a gift from the gods!",
                          "Please choose a bonus you would like to receive",
                          sep = "\n"
                          )
                    available_gifts = get_gifts()
                    print("\n1. " + available_gifts[0],
                          "\n",
                          "2. " + available_gifts[1],
                          "\n",
                          "3. " + available_gifts[2],
                          sep = "\n"
                    )
                    
                    while True:
                        choice = int(input("\n"))
                        if choice > 0 and choice <= 3:
                            set_gift(available_gifts[choice-1])
                        break
                    else:
                        print("that is not a valid choice, please choose again")
                        continue
                else:
                    pass
                character_menu()
                break        
            elif turn == 5: #if there has been 5 turn cycles display skills 
                available_skills = get_skills()
                print("\nYou will gain the skill you choose")
                print("\n\n1. " + available_skills[0],
                      "\n",
                      "2. " +  available_skills[1],
                      "\n",
                      "3. " + available_skills[2],
                    sep = "\n"
                        )
                while True:
                    choice = int(input("\n"))
                    if choice > 0 and choice <= 3:
                        print("You have chosen to gain the " + available_skills[choice-1] + " skill!")
                        skills.append(available_skills[choice-1])
                        break
                    else:
                        print("that is not a valid choice, please choose again")
                        continue
                turn += 1
                character_menu()
                break
            else: #if there has been more than 5 turn cycles reset the cycle and start again
                turn = 1
                continue
    else:
        print("You have hit the level limit! You cannot level up anymore! Bask in the glory of reaching max level")
        character_menu()
        

#allows the player to view the stats of their character
def view_character():
    print(character_name,
          "Class: " + character + " Level: " + str(level),
          "\n",
          "Attributes",
          "----------",
          "Strength- " + str(attributes["Strength"]) + " Constitution- " + str(attributes["Constitution"]) + " Dexterity- " + str(attributes["Dexterity"])  + " Intelligence- " + str(attributes["Intelligence"]) + " Luck- " + str(attributes["Luck"]),
          "\n",
          "Skills",
          "-------",
          sep = "\n"
          )
    print(", ".join(skills))
    input("\npress enter to return to the previous menu")
    character_menu()
     
#saves the characters stats to a file
def save():
    try:
        file_name = r"character_saves/" + character_name
        file_object = open(file_name, 'wb')  
    except:
        print("Unable to create file on disk.")
        file_object.close()
        main()
    finally:
        pickle.dump(character_name, file_object)
        pickle.dump(character, file_object)
        pickle.dump(level, file_object)
        pickle.dump(gift_counter, file_object)
        pickle.dump(turn, file_object)
        pickle.dump(attributes, file_object)
        pickle.dump(skills, file_object)
        pickle.dump(milestones, file_object)
        file_object.close()
        input("Your character has been saved! Select load character in the main menu to access them\n\nPress enter to return to the main menu")
        main()
    
                

#displays the character menu
def character_menu():
    print("""     
                         Character Menu
                        ----------------
What would you like to do?
        
                1. Level up
                2. View Character
                3. Help
                4. Save and Quit
    """)
    
    while True:
        choice = input("\n")
        if choice == "1":
            level_up()
        elif choice == "2":
            view_character()
        elif choice == "3":
            help()
            character_menu()
        elif choice == "4":
            choice = input("Would you like to save your character (y/n)?")
            while True:
                if choice.lower() == "y":
                    save()
                elif choice.lower() == "n":
                    break
                else:
                    continue
            main()   
        else:
            print("Sorry that isn't a valid choice, please try again")
            continue

#creates a new character by selecting 3 random characters and letting the player pick one    
def new_character():
    character_list = ["Warrior", "Ranger", "Rogue", "Wizard", "Necromancer", "Druid"]
    available_chars = []
    counter = 0
    global character_name
    global attributes
    global skills
    global character
    global turn
    global level
    global gift_counter
    global milestones
    # reset character stats at the start of a new character
    milestones = ["Strength10", "Strength25", "Strength50", "Constitution10", "Constitution25", "Constitution50", "Dexterity10", "Dexterity25", "Dexterity50", "Intelligence10", "Intelligence25", "Intelligence50", "Luck10", "Luck25", "Luck50" ]
    gift_counter = 0
    level = 0
    turn = 1 
    
    while counter < 3:
        rand = random.randint(0,len(character_list )- 1)
        available_chars.append(character_list[rand])
        del character_list[rand]
        counter += 1
    counter = 0
    print("Your adventure begins here!\n\nPlease select a class from the options below. This will determine your base stats and skills")
    for i in available_chars:
        counter += 1
        if i == "Warrior":
            attributes = {"Strength":6, "Constitution":5, "Dexterity":2, "Intelligence":1, "Luck":1}
            skills =["cleave", "guard"]
        elif i == "Ranger":
            attributes = {"Strength":1, "Constitution":3, "Dexterity":6, "Intelligence":2, "Luck":3}
            skills =["regular shot", "dodge"]
        elif i == "Rogue":
            attributes = {"Strength":2, "Constitution":2, "Dexterity":5, "Intelligence":1, "Luck":5}
            skills =["stab", "spare change", "dodge"]
        elif i == "Wizard":
            attributes = {"Strength":1, "Constitution":2, "Dexterity":1, "Intelligence":8, "Luck":3}
            skills =["magic missile", "fire ball"]    
        elif i == "Necromancer":
            attributes = {"Strength":3, "Constitution":4, "Dexterity":1, "Intelligence":6, "Luck":1}
            skills =["slash", "raise undead"] 
        elif i == "Druid":
            attributes = {"Strength":3, "Constitution":4, "Dexterity":3, "Intelligence":4, "Luck":1}
            skills =["club", "werewolf"] 
        
        print(str(counter) + ". " +  i,
              "\nAttributes",
              "\n---------",
               "\nStrength- " + str(attributes["Strength"]) + " Constitution- " + str(attributes["Constitution"]) + " Dexterity- " + str(attributes["Dexterity"])  + " Intelligence- " + str(attributes["Intelligence"]) + " Luck- " + str(attributes["Luck"]),
               "\n", 
               "\nSkills",
               "\n---------",
               "\n"
              )   
        print(", ".join(skills))
        
    while True:   
        choice = input("\n")
        if choice == "":
            print("that is not a valid choice, please choose again!")
            continue
        else:
            choice = int(choice)
        if choice <= len(available_chars):
            character = available_chars[choice - 1]
            break
        else:
            print("that is not a valid choice, please choose again!")
            continue
        
    if character == "Warrior":
        attributes = {"Strength":6, "Constitution":5, "Dexterity":2, "Intelligence":1, "Luck":1}
        skills =["cleave", "guard"]
    elif character == "Ranger":
        attributes = {"Strength":1, "Constitution":3, "Dexterity":6, "Intelligence":2, "Luck":3}
        skills =["regular shot", "dodge"]
    elif character == "Rogue":
        attributes = {"Strength":2, "Constitution":2, "Dexterity":5, "Intelligence":1, "Luck":5}
        skills =["stab", "spare change", "dodge"]
    elif character == "Wizard":
        attributes = {"Strength":1, "Constitution":2, "Dexterity":1, "Intelligence":8, "Luck":3}
        skills =["magic missile", "fire ball"]    
    elif character == "Necromancer":
        attributes = {"Strength":3, "Constitution":4, "Dexterity":1, "Intelligence":6, "Luck":1}
        skills =["slash", "raise undead"] 
    elif character == "Druid":
        attributes = {"Strength":3, "Constitution":4, "Dexterity":3, "Intelligence":4, "Luck":1}
        skills =["club", "werewolf"] 
        
    
       
    character_name = input(character + "? A fine choice indeed! Please choose a name for your character(note that saving a\n character with the same name as another will delete the old one): ")
    character_menu()
   


        
#displays the main menu   
def main():   
    print("Hello and welcome to the roguelike progression system. Below is the main menu, please make a choice to continue.")
    while True:
        print("""
                         Main Menu
                        -----------
        
                1. New Character
                2. Load Character
                3. Help
                4. Quit
                    """)
        
        choice = input("\n")
        
        if choice == "1":
            new_character()
        elif choice == "2":
            load()
        elif choice == "3":
            help()
            continue
        elif choice == "4":
                print("quitting...")
                break
        else:
            print("thats option is not available, please try again\n")
            continue   
    
main()    
    
    
























# project3_part1_student_files
## Student infromation:
- Jesus Longares
- Id: 008685606
- https://github.com/Jhaysus/-project3_part1_student_files.git
## Collaboration & Sources
- Partner: None
- Sources:
- https://www.ascii-code.com/
- https://www.geeksforgeeks.org/java/how-to-check-if-a-string-contains-only-ascii-in-java/
- https://www.geeksforgeeks.org/cpp/tokenizing-a-string-cpp/
- https://stackoverflow.com/questions/52878065/converting-input-from-lowercase-to-uppercase-using-ascii-codes-in-c
- https://cplusplus.com/reference/istream/istream/

- 
## Implementation Details:
- Scanner functions

- majority of the things I found on how ACSII and istream function come from the defintions given from the sources. I was unfamiliar on how they work and used the functions given on canvas to be able extract from files to check if they exist
- I wanted to be able to go through the word and detect if it's ASCII so as it goes through, it just builds the word and if it detects an apostrophe
- Reads one char at a time and skips anything that isn't a character unless an aposphrope. It keeps adding letters until reaching a seperator.
- It lowercases the char before starting
- Reads the next word from the stream, returning a std::string; returns an empty string when there are no more words, token is created.
- A token is letters a–z with optional internal apostrophes. Allowed patterns: [a–z]+ or [a–z]+’[a–z]+ (apostrophes only between letters) Drop leading/trailing apostrophes. They never include spaces, tabs, or newlines.
- After the loop, trims any trailing ' so tokens never end with an apostrophe.

## Testing
- Tested the diff to see if there would be any errors and it returned nothing back

```sh
jlongares@blue:~/cs315/project3_part1_student_files$ bash compile_and_test.bash for_the_love_of_a_man.txt
Compiling project...
Running program with input file 'input_output/for_the_love_of_a_man.txt'...
diff input_output/for_the_love_of_a_man.tokens /home/faculty/kooshesh/cs315_f2025_p3_part1/part1_tokens_files//for_the_love_of_a_man.tokens
jlongares@blue:~/cs315/project3_part1_student_files$ bash compile_and_test.bash the_toil_of_trace_and_trail.txt
Compiling project...
Running program with input file 'input_output/the_toil_of_trace_and_trail.txt'...
diff input_output/the_toil_of_trace_and_trail.tokens /home/faculty/kooshesh/cs315_f2025_p3_part1/part1_tokens_files//the_toil_of_trace_and_trail.tokens
jlongares@blue:~/cs315/project3_part1_student_files$ bash compile_and_test.bash the_law_of_club_and_fang.txt
Compiling project...
Running program with input file 'input_output/the_law_of_club_and_fang.txt'...
diff input_output/the_law_of_club_and_fang.tokens /home/faculty/kooshesh/cs315_f2025_p3_part1/part1_tokens_files//the_law_of_club_and_fang.tokens
jlongares@blue:~/cs315/project3_part1_student_files$ bash compile_and_test.bash into_the_primitive.txt
Compiling project...
Running program with input file 'input_output/into_the_primitive.txt'...
diff input_output/into_the_primitive.tokens /home/faculty/kooshesh/cs315_f2025_p3_part1/part1_tokens_files//into_the_primitive.tokens
jlongares@blue:~/cs315/project3_part1_student_files$ bash compile_and_test.bash tableOfContents_TheCallOfWild.txt
Compiling project...
Running program with input file 'input_output/tableOfContents_TheCallOfWild.txt'...
diff input_output/tableOfContents_TheCallOfWild.tokens /home/faculty/kooshesh/cs315_f2025_p3_part1/part1_tokens_files//tableOfContents_TheCallOfWild.tokens
jlongares@blue:~/cs315/project3_part1_student_files$ bash compile_and_test.bash the_sounding_of_the_call.txt
Compiling project...
Running program with input file 'input_output/the_sounding_of_the_call.txt'...
diff input_output/the_sounding_of_the_call.tokens /home/faculty/kooshesh/cs315_f2025_p3_part1/part1_tokens_files//the_sounding_of_the_call.tokens

```
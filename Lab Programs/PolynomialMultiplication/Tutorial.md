# Polynomial Multiplication Program

This program multiplies two polynomials represented by linked lists, combining terms with the same power after multiplication.

## Sample Inputs and Outputs

### Example 1
**Input:**
3 2 1 2 3 4 5
**Output:**
4|4 --> 13|3 --> 22|2 --> 15|1 --> x

### Example 2
**Input:**
4 3 3 0 5 7 2 1 4
**Output:**
6|6 --> 3|5 --> 22|4 --> 31|3 --> 35|2 --> 28|1 --> x

### Example 3
**Input:**
2 2 1 1 1 1
**Output:**
1|2 --> 2|1 --> 1|0 --> x


This output format displays the resulting polynomial in the form `coefficient|power -->`, showing each term of the polynomial in descending order by power.

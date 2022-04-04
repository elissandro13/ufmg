

for x in range (1,17):
  name = "pratica4ex" + str(x) + ".c"
  f = open(name, "a")
  f.write("#include <stdio.h>\n#include <math.h>\n#include \"pratica4.h\" \n\n\nint main() \n{\n\n return 0;\n}")
  f.close()

 

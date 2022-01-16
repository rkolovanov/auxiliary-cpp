import datetime
import uuid
from string import Template

projectName = "auxiliary-cpp"
projectNamespace = "Auxiliary"

namespaceName = input("Название пространства имен: ")
className = input("Название класса: ")
classId = str(uuid.uuid4()).upper().replace("-", "_")

values = {
    "projectName": projectName,
    "projectNamespace": projectNamespace,
    "namespaceName": namespaceName,
    "className": className,
    "classId": classId,
    "year": datetime.datetime.now().year
}

with open("class.h.template", "r") as fileTemplate:
    template = Template(fileTemplate.read())
    content = template.substitute(values)

    with open("{}.h".format(className), "w") as outputFile:
        outputFile.write(content)

with open("class.cpp.template", "r") as fileTemplate:
    template = Template(fileTemplate.read())
    content = template.substitute(values)

    with open("{}.cpp".format(className), "w") as outputFile:
        outputFile.write(content)

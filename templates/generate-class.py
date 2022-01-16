from datetime import datetime
from string import Template
from uuid import uuid4

headerTemplateFilePath = "class.h.template"
sourceTemplateFilePath = "class.cpp.template"

projectName = "auxiliary-cpp"
projectNamespace = "Auxiliary"
projectDescription = "Библиотека вспомогательных решений"

namespaceName = input("Название пространства имен: ")
className = input("Название класса: ")
classId = str(uuid4()).upper().replace("-", "_")
headerFileName = "{}.h".format(className)
sourceFileName = "{}.cpp".format(className)

templateValues = {
    "projectName": projectName,
    "projectNamespace": projectNamespace,
    "projectDescription": projectDescription,
    "namespaceName": namespaceName,
    "className": className,
    "classId": classId,
    "classHeaderIncludePath": "{}/{}/{}.h".format(projectNamespace.lower(), namespaceName.lower(), className),
    "year": datetime.now().year,
    "headerFileName": headerFileName,
    "sourceFileName": sourceFileName
}

with open(headerTemplateFilePath, "r") as templateFile:
    template = Template(templateFile.read())
    content = template.substitute(templateValues)

    with open(headerFileName, "w") as outputFile:
        outputFile.write(content)

with open(sourceTemplateFilePath, "r") as templateFile:
    template = Template(templateFile.read())
    content = template.substitute(templateValues)

    with open(sourceFileName, "w") as outputFile:
        outputFile.write(content)

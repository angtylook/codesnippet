println "Hello world!"

def x  = 1
println x

x = new java.util.Date()
println x

x = "groovy!"
println x

def technologies = []
technologies.add("Grails")
technologies << "Groovy"
technologies.addAll(["Gradle", "Griffon"])

println technologies

technologies.remove("Griffon")
technologies = technologies - 'Grails'

technologies.each { println "Technology: $it" }
technologies.eachWithIndex { it, i -> println "$i: $it"}

contained = 


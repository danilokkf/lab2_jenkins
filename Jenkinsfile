pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // Ця команда автоматично завантажить код з вашого GitHub, 
                // який ви вкажете в налаштуваннях завдання Jenkins
                checkout scm
            }
        }
        
        stage('Build') {
            steps {
                echo 'Building Project...'
                // Крок для збірки проекту. 
                // Ми використовуємо Rebuild та Debug конфігурацію для чистоти експерименту.
                bat '\"C:\\Program Files\\Microsoft Visual Studio\\18\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe\" test_repos.sln /t:Rebuild /p:Configuration=Debug /p:Platform=x64'
            }
        }

        stage('Test') {
            steps {
                echo 'Running Tests...'
                // Запуск тестів.
                // Аргумент --gtest_output створює звіт, який потім прочитає Jenkins
                bat 'x64\\Debug\\test_repos.exe --gtest_output=xml:test_report.xml'
            }
        }
    }

    post {
        always {
            // Цей крок шукає файл test_report.xml і будує графіки результатів
            junit 'test_report.xml'
        }
    }
}
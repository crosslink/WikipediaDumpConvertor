#!/bin/bash

sed 's/<title>Wikipedia：/<title>/g' | sed 's/<url>.*<\/url>//g' | sed '/^$/d' 

FROM gcc:latest 
COPY . /home 
WORKDIR /home 
RUN gcc simple-code.c -o run 
CMD ["./run"] 
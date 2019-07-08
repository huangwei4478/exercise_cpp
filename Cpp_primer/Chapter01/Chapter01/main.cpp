

matrix read_matrix_file(const char* fname, ...) {
    fstream f(fname);
    
    if (!f.is_open()) {
        throw "Cannot open file."
    }
}

template <class T, class ID>
class CrudRepository
{
public:
    virtual void create(const T& object) = 0;
    virtual const T& read(ID id) const = 0;
    virtual void update(ID id, const T& newObject) = 0;
    virtual void d_remove(ID id) = 0;
};


namespace MyLibrary
{
    public interface IEntity
    {
        void Initialize(string row);
        string GetFileName();
        string GetFileStr();
        int GetId();
        void SetId(int newId);
    }
}
